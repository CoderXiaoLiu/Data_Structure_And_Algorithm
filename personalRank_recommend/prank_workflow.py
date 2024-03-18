# -*- coding: utf-8 -*-
import sys
import time
import os
from prank import Graph, PersonalRank

def delete_substr_method2(in_str, in_substr):
    start_loc = in_str.find(in_substr)
    len_substr = len(in_substr)
    res_str = in_str[:start_loc] + in_str[start_loc + len_substr:]
    return res_str

#改动这里的user_id，即可改推荐的目标用户
def run(userid):
    assert os.path.exists('data/ratings.csv'), \
        'File not exists in path, run preprocess.py before this.'
    print('Start..')
    start = time.time()
    if not os.path.exists('data/prank.graph'):
        Graph.gen_graph()
    if not os.path.exists('data/prank_'+str(userid)+'.model'):
        PersonalRank().train(user_id=userid)
    movies = PersonalRank().predict(user_id=userid)
    #for movie in movies:
        #print(movie)
    print('Cost time: %f' % (time.time() - start))
    return movies

if __name__ == '__main__':
    target = 169
    run(target)

    result3 = run(target)  # 三个result的输出格式为[[str，浮点数],[str，浮点数]......]
    result3 = list(result3)
    # print(result3)
    # print(len(result3))

    for j in result3:
        print(delete_substr_method2(j[0],"item_"))

    # result = []
    # count = 0
    #
    # with open("recommand_result_"+str(target)+".txt",'w', encoding='utf-8') as f:
    #     for ok in result:
    #         if count < 10:
    #             print(ok)
    #             f.write(str(ok)+"\n")
    #             count = count+1