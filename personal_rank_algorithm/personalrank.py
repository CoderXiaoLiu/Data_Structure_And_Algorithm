"""
使用numpy
"""
import time
import networkx
import functools
import numpy as np
from numpy.linalg import solve
from scipy.sparse import csr_matrix
from scipy.sparse.linalg import gmres, lgmres


class PersonalRank(object):
	def __init__(self, alpha):
		self.alpha = alpha

	def log_time(func):
		@functools.wraps(func)
		def wrapper(*args, **kwargs):
			start = time.time()
			rs = func(*args, **kwargs)
			print('%s:duration:%.6f' % (func.__name__, time.time() - start))
			return rs

		return wrapper

	@log_time
	def train(self, graph, root, iterations):
		rank = {x: 0 for x in graph.nodes}
		rank[root] = 1
		count = 0
		# 迭代
		while True:
			tmp = {x: 0 for x in graph.nodes}
			# 节点i和它的出度节点集合ri
			for node in graph.nodes:
				out_nodes = list(graph.neighbors(node))
				out_degree = len(out_nodes)
				# 节点j和边权重
				for j in out_nodes:
					data = graph.get_edge_data(node, j)
					tmp[j] += self.alpha * rank[node] / out_degree * data['weight']
			# 每次游走都是从root出发，因此root节点的权重需要加上1- alpha
			tmp[root] += (1 - self.alpha)
			rank = tmp
			count += 1
			if count >= iterations:
				# print('PersonalRank:%d' % count)
				break
		return rank


if __name__ == '__main__':
	graph = networkx.DiGraph()
	graph.add_edge('任小牛', '笔记本电脑', weight=1)
	graph.add_edge('任小牛', '风扇', weight=0.1)
	graph.add_edge('任小牛', '键盘', weight=0.1)
	graph.add_edge('卡洛斯', '笔记本电脑', weight=0.2)
	graph.add_edge('卡洛斯', '风扇', weight=0.3)
	graph.add_edge('詹姆斯', '风扇', weight=0.4)
	graph.add_edge('詹姆斯', '键盘', weight=0.5)
	graph.add_edge('卡尔', '笔记本电脑', weight=0.7)
	graph.add_edge('卡尔', '键盘', weight=0.9)

	rank = PersonalRank(alpha=0.85)
	target = '任小牛'
	rs = rank.train(graph, target, 2000)
	rs = sorted(rs.items(), key=lambda x: x[1], reverse=True)
	print(rs)

	"""
train:duration:0.013963
[('任小牛', 0.15000000000000002), ('笔记本电脑', 0.0425), ('风扇', 0.00425), ('键盘', 0.00425), ('卡洛斯', 0), ('詹姆斯', 0), ('卡尔', 0)]
	"""