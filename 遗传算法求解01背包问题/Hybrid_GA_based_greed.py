# -*- coding: utf-8 -*-
"""
遗传算法
利用贪心算法的思想对传统遗传算法的繁殖算子进行改进
"""
import random

SCORE_NONE = -1.0

class Life(object):
      """个体类"""
      def __init__(self, aGene = None):
            self.gene = aGene
            self.score = SCORE_NONE

class Hybrid_GA_based_greed(object):
    """遗传算法类"""

    def __init__(self, aCrossRate, aMutationRage, aLifeCount, aGeneLenght, aMatchFun=lambda life: 1):
        self.croessRate = aCrossRate              # 交叉概率
        self.mutationRate = aMutationRage         # 突变率
        self.lifeCount = aLifeCount               # 种群大小
        self.geneLenght = aGeneLenght             # 染色体长度
        self.matchFun = aMatchFun                 # 适值函数
        self.lives = []                           # 种群
        self.best = None                          # 保存这一代中最好的个体
        self.generation = 1                       # 迭代次数
        self.crossCount = 0                       # 交叉个数
        self.mutationCount = 0                    # 变异个数
        self.bounds = 0.0                         # 适配值之和，用于选择时计算概率,公式：Fi/sum(Fi).其中Fi为个体i对应的适应值
        self.value_density = []                   # 价值密度
        self.init()

        self.initPopulation()

    def init(self):
        self.goods = []
        f = open("test", "r")  # 设置文件对象
        line = f.readline()
        line = line[:-1]
        self.Volume = float(line.split()[0])  # 背包容量
        # print(self.allGoods)
        while line:  # 直到读取完文件
            line = f.readline()  # 读取一行文件，包括换行符
            line = line[:-1]  # 去掉换行符，也可以不去
            self.goods.append([float(line.split()[i]) for i in range(len(line.split()))])
        self.goods = self.goods[:-1]  # 去掉换行
        # print(self.goods,len(self.goods))
        n = len(self.goods)
        self.value_density = [[self.goods[i][1] / self.goods[i][0], i] for i in range(n)]
        self.value_density.sort(key=lambda x: x[0], reverse=True)
        # print(self.value_density)
        f.close()  # 关闭文件

    def initPopulation(self):
        """初始化种群"""
        self.lives = []
        for i in range(self.lifeCount):
            gene = [random.randint(0,1) for x in range(self.geneLenght)] # 初始化染色体
            # shuffle() 方法将序列的所有元素随机排序。
            random.shuffle(gene)
            life = Life(gene) # 生成个体
            self.lives.append(life)

    def judge(self):
        """评估，计算每一个个体的适配值"""
        self.bounds = 0.0
        self.best = self.lives[0]
        for life in self.lives:
            # print(life.gene)
            self.greedy(life.gene)
            life.score = self.matchFun(life) # 获得个体的适应值
            self.bounds += life.score
            if self.best.score < life.score:
                self.best = life # 选择最优个体

    def greedy(self, gene):
        """贪婪算子"""
        # print(self.value_density)
        cnt = 0
        for i in range(self.geneLenght):
            cnt += gene[i] * self.goods[i][0]

        if cnt < self.Volume:
            for j in range(self.geneLenght):
                i = self.value_density[j][1]
                if cnt + self.goods[i][0] < self.Volume and gene[i] == 0:
                    cnt += self.goods[i][0]
                    gene[i] = 1
                else:
                    break
        else:
            for j in range(self.geneLenght - 1, -1, -1):
                i = self.value_density[j][1]
                if cnt <= self.Volume:
                    break
                if gene[i] == 1:
                    cnt -= self.goods[i][0]
                    gene[i] = 0


    def cross(self, parent1, parent2):
        """
        交叉
        随机从其他染色体上截取一段基因，与原染色体上的此段基因片段交换，来得到新染色体
        """
        index1 = random.randint(0, self.geneLenght - 1)
        index2 = random.randint(index1, self.geneLenght - 1)
        newGene = []

        newGene.extend(parent1.gene[:index1])
        newGene.extend(parent2.gene[index1:index2])
        newGene.extend(parent1.gene[index2:])

        self.crossCount += 1
        # print(newGene)
        self.greedy(newGene)
        return newGene      # 返回交叉后的parent1.gene

    def mutation(self, gene):
        """变异算子，突变,两个基因互换位置"""
        index1 = random.randint(0, self.geneLenght - 1)
        newGene = gene[:]       # 产生一个新的基因序列，以免变异的时候影响父种群
        newGene[index1] = (newGene[index1] + 1) % 2
        # print(newGene)
        if random.random() < self.mutationRate:
            self.mutation(newGene)
        self.mutationCount += 1
        # print(self.Value_density)
        self.greedy(newGene)
        return newGene

    def getOne(self):
        """选择一个个体,适应值越大，则个体被选中的概率越大，选择算子"""
        r = random.uniform(0, self.bounds)
        for life in self.lives:
            r -= life.score
            if r <= 0:
                return life

        raise Exception("选择错误", self.bounds)

    def newChild(self):
        """产生新后代"""
        parent1 = self.getOne()
        rate = random.random()      # 0~1的随机数

        # 按概率交叉
        if rate < self.croessRate:
            # 交叉
            parent2 = self.getOne()
            gene = self.cross(parent1, parent2)
        else:
            gene = parent1.gene

        # 按概率突变
        rate = random.random()
        if rate < self.mutationRate:
            gene = self.mutation(gene)

        return Life(gene)

    def next(self):
        """产生下一代"""
        self.judge()
        newLives = []
        newLives.append(self.best)      # 把最好的个体加入下一代
        while len(newLives) < self.lifeCount:
            newLives.append(self.newChild())
        self.lives = newLives       #更新种群
        self.generation += 1        #更新迭代次数

