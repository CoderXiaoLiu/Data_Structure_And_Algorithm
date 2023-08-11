# https://leetcode.cn/problems/generate-parentheses/description/

def generateParenthesis(n: int) -> list[str]:
    ans = []

    def dfs(s, leftSum, rightSum):
        if leftSum == n and rightSum == n:
            ans.append(s)
            return
        if leftSum <= n:
            dfs(s + "(", leftSum + 1, rightSum)
        if rightSum < leftSum:
            dfs(s + ")", leftSum, rightSum + 1)

    dfs("", 0, 0)
    return ans

n = int(input())
# print(generateParenthesis(n))
ans_list = generateParenthesis(n)
for element in ans_list:
    print(element)