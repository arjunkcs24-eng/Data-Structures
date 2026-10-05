class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        S,T=dict(),dict()
        for n,m in zip(s,t):
            S[n]=S.get(n,0)+1
            T[m]=T.get(m,0)+1
        if(S==T):
            return True
        return False