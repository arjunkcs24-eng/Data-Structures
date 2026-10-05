class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        char=set(t)
        if(len(s)!=len(t)):
            return False
        for ch in char:
            if(s.count(ch)!=t.count(ch)):
                return False
        return True