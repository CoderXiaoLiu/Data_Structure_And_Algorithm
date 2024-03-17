"""
使用了scipy的稀疏矩阵
"""
import time
import networkx
import functools
import numpy as np
from numpy.linalg import solve
from scipy.sparse import csr_matrix
from scipy.sparse.linalg import gmres, lgmres

def _get_weight_matrix(graph, is_using_out=True):
    nodes = list(graph.nodes)
    matrix = networkx.adjacency_matrix(graph).A
    if is_using_out:
        degrees = [1.0/graph.degree(node) for node in nodes]
        degrees = np.tile(degrees, (len(nodes), 1))
        matrix = csr_matrix(np.multiply(matrix, degrees))
    return matrix

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

	def _get_weight_matrix(graph, is_using_out=True):
		nodes = list(graph.nodes)
		matrix = networkx.adjacency_matrix(graph).A
		if is_using_out:
			degrees = [1.0 / graph.degree(node) for node in nodes]
			degrees = np.tile(degrees, (len(nodes), 1))
			matrix = csr_matrix(np.multiply(matrix, degrees))
		return matrix

	@log_time
	def train_matrix(self, graph, root):
		"""
		使用矩阵求解
		:param graph: networkx.DiGraph
		:param alpha: 系数，一般为0.8左右
		:param root: 从哪出发
		:return:
		"""
		# 生成矩阵
		nodes = list(graph.nodes)
		matrix = _get_weight_matrix(graph)
		# 除了边的权重外，还需要为每个点乘以出度的倒数
		r0 = np.matrix([[1 if node == root else 0] for node in nodes])
		n = matrix.shape[0]
		# 求解
		A = np.eye(n) - self.alpha * matrix.T
		b = (1 - self.alpha) * r0
		r = solve(A, b)
		rank = {}
		for j in range(n):
			rank[nodes[j]] = r[j, 0]
		return rank

	@log_time
	def train_csr_matrix(self, graph, root):
		# 生成矩阵
		nodes = list(graph.nodes)
		matrix = _get_weight_matrix(graph)
		n = matrix.shape[0]
		r0 = np.matrix([[1 if node == root else 0] for node in nodes])
		A = np.eye(n) - self.alpha * matrix.T
		b = (1 - self.alpha) * r0
		r = lgmres(A, b, tol=1e-8, atol=1e-8, maxiter=1)[0]
		rank = {}
		for j in range(n):
			rank[nodes[j]] = r[j]
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
	# 另一个
	# rs = rank.train_matrix(graph, target)
	# rs = sorted(rs.items(), key=lambda x: x[1], reverse=True)
	# print(rs)
	# gmres
	rs = rank.train_csr_matrix(graph, target)
	rs = sorted(rs.items(), key=lambda x: x[1], reverse=True)
	print(rs)

"""
train_matrix:duration:0.001995
[('任小牛', 0.15000000000000002), ('笔记本电脑', 0.0425), ('风扇', 0.00425), ('键盘', 0.00425), ('卡洛斯', 0.0), ('詹姆斯', 0.0), ('卡尔', -0.0)]
train_csr_matrix:duration:0.005985
[('任小牛', 0.15000000000000002), ('笔记本电脑', 0.04249999999999999), ('风扇', 0.004249999999999999), ('键盘', 0.004249999999999999), ('卡洛斯', 0.0), ('詹姆斯', 0.0), ('卡尔', 0.0)]
"""