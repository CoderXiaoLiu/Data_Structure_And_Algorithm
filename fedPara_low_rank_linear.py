import torch
import torch.nn as nn
import numpy as np
import torch.nn.functional as F

class LowRank(nn.Module):
    def __init__(self,
                 in_channels: int,
                 out_channels: int,
                 low_rank: int):
        super(LowRank,self).__init__()
        self.in_channels = in_channels
        self.out_channels = out_channels
        self.low_rank = low_rank

        # Define linear layers
        # self.T_linear = nn.Parameter(torch.empty(size=(low_rank, low_rank)), requires_grad=True)
        # self.O_linear = nn.Parameter(torch.empty(size=(low_rank, out_channels)), requires_grad=True)
        # self.I_linear = nn.Parameter(torch.empty(size=(low_rank, in_channels)), requires_grad=True)

        self.T_linear = nn.Linear(low_rank, low_rank, bias=False)
        self.O_linear = nn.Linear(out_channels, low_rank, bias=False)
        self.I_linear = nn.Linear(in_channels, low_rank, bias=False)

        # Initialization
        self._init_parameters()

    def _init_parameters(self):
        # Initialization affects the convergence stability for our parameterization
        gain = nn.init.calculate_gain('relu', 0)
        std_t = gain / np.sqrt(self.low_rank*self.low_rank)
        std_o = gain / np.sqrt(self.out_channels * self.low_rank)
        std_i = gain / np.sqrt(self.in_channels * self.low_rank)

        nn.init.normal_(self.T_linear.weight, 0, std_t)
        nn.init.normal_(self.O_linear.weight, 0, std_o)
        nn.init.normal_(self.I_linear.weight, 0, std_i)

    def forward(self, x):
        T = self.T_linear.weight.view(self.low_rank, self.low_rank)
        O = self.O_linear.weight  # Transpose to match dimensions for multiplication
        I = self.I_linear(x)

        result = torch.mm(I,T)
        result = torch.mm(result,O)

        return result


class Linea_new(nn.Module):
    def __init__(self, in_features, out_features, bias=False, ratio=0.5):
        super(Linea_new,self).__init__()
        self.in_features = torch.tensor(in_features)
        self.out_features = torch.tensor(out_features)
        self.bias = bias
        self.ratio = ratio
        self.low_rank = int(self._calc_from_ratio())

        self.W1 = LowRank(in_features, out_features, self.low_rank)
        self.bias = nn.Parameter(torch.zeros(out_features)) if bias else None

    def _calc_from_ratio(self):
        r3 = float(self.in_features*self.out_features*self.ratio)/float(self.in_features+self.out_features)
        r3 = torch.floor(torch.tensor(r3))
        return r3

    def forward(self, x):
        print(self.low_rank)
        # Hadamard product of two submatrices
        out = self.W1(x)
        return out

if __name__ == '__main__':
    # Example usage
    in_features = 300
    out_features = 300
    # linear_layer = Linea_new(in_features, out_features)
    # input_tensor = torch.randn(3, in_features)  # Example input tensor
    # output_tensor = linear_layer(input_tensor)
    # print(output_tensor.shape)  # Output shape: [batch_size, out_channels, height, width]

    layer_ori = nn.Linear(300,300)
    orig_num_params = sum(p.numel() for p in layer_ori.parameters() if p.requires_grad)
    layer1 = Linea_new(300, 300, ratio=0.1)
    layer3 = Linea_new(300, 300, ratio=0.3)
    layer5 = Linea_new(300, 300, ratio=0.5)
    layer7 = Linea_new(300, 300, ratio=0.6)
    layer9 = Linea_new(300, 300, ratio=0.8)

    num1 = sum(p.numel() for p in layer1.parameters() if p.requires_grad)
    num3 = sum(p.numel() for p in layer3.parameters() if p.requires_grad)
    num5 = sum(p.numel() for p in layer5.parameters() if p.requires_grad)
    num7 = sum(p.numel() for p in layer7.parameters() if p.requires_grad)
    num9 = sum(p.numel() for p in layer9.parameters() if p.requires_grad)

    print(orig_num_params, num1, num1 / orig_num_params)
    print(orig_num_params, num3, num3 / orig_num_params)
    print(orig_num_params, num5, num5 / orig_num_params)
    print(orig_num_params, num7, num7 / orig_num_params)
    print(orig_num_params, num9, num9 / orig_num_params)
