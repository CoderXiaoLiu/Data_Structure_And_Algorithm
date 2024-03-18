# -*- coding: utf-8 -*-
import sys
from preprocess import Channel
from prank_workflow import run as prank
import traceback

def delete_substr_method2(in_str, in_substr):
    start_loc = in_str.find(in_substr)
    len_substr = len(in_substr)
    res_str = in_str[:start_loc] + in_str[start_loc + len_substr:]
    return res_str

def manage():
    target = int(sys.argv[2])  # 这里用运行参数代表用户id赋值给target
    result3 = prank(target) #三个result的输出格式为[[str，浮点数],[str，浮点数]......]
    result3 = list(result3)
    print(result3)
    print(len(result3))
    result = []
    count = 0


    with open("recommand_result_"+sys.argv[2]+".txt",'w', encoding='utf-8') as f:
        for ok in result:
            if count < 10:
                print(ok)
                f.write(str(ok)+"\n")
                count = count+1
    sys.exit()


if __name__ == '__main__':
    target = 5
    manage()