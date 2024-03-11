"""
基于贪心的混合遗传算法求解01背包问题
"""
import random
import math
from Hybrid_GA_based_greed import Hybrid_GA_based_greed


class KP(object): #01背包类
    def __init__(self, aLifeCount=200):
        # 初始化
        self.init()
        self.lifeCount = aLifeCount

        self.ga = Hybrid_GA_based_greed(aCrossRate=0.7,  # 交叉概率
                                        aMutationRage=0.1,  # 突变率
                                        aLifeCount=self.lifeCount,  # 种群大小
                                        aGeneLenght=len(self.goods),  # 染色体长度(物品个数),其中基因为物品排列顺序。
                                        aMatchFun=self.matchFun())   # 适值函数

    def init(self):
        self.goods = []
        f = open("test", "r")  # 设置文件对象
        line = f.readline()
        line = line[:-1]
        self.Volume = float(line.split()[0]) # 背包容量
        # print(self.allGoods)
        while line:  # 直到读取完文件
            line = f.readline()  # 读取一行文件，包括换行符
            line = line[:-1]  # 去掉换行符，也可以不去
            self.goods.append([float(line.split()[i]) for i in range(len(line.split()))])
        self.goods = self.goods[:-1]  # 去掉换行
        # print(self.goods,len(self.goods))
        # print(self.value_density)
        f.close()  # 关闭文件

    def price(self, order):
        # order中存放着选择
        price = [0.0, 0.0]
        for i in range(0, len(self.goods)):
            price[0] += self.goods[i][0] * order[i]  # 重量
            price[1] += self.goods[i][1] * order[i]  # 价值
        return price

    def matchFun(self):
        """适值函数"""
        return lambda life: self.price(life.gene)[1] / sum(self.goods[i][0] for i in range(len(self.goods)))
        # Max = max(self.Volume, abs(sum(self.goods[i][0] for i in range(len(self.goods))) - self.Volume))
        #
        # return lambda life: self.price(life.gene)[1] / (self.price(life.gene)[0] + 1 - self.Volume) * \
        #                     (1 - abs(self.price(life.gene)[0] - self.Volume) / Max) \
        #     if self.price(life.gene)[0] > self.Volume \
        #     else self.price(life.gene)[1] * (1 - abs(self.price(life.gene)[0] - self.Volume) / Max)

    # n为迭代次数
    def run(self, n=0):
        price = [0, 0]
        while n > 0:
            self.ga.next()
            price = self.price(self.ga.best.gene)
            n -= 1
            print("generation:", self.ga.generation, "  weights :", price[0], "----", "price :", price[1])
        print(self.ga.best.gene)
        return price


def main():
    '''多次运算，取众数即为最终值'''
    res = []
    for i in range(1):
        tsp = KP(300)
        res.append(tsp.run(200))
    print(res)
    print(max(res, key=res.count))


if __name__ == '__main__':
    main()