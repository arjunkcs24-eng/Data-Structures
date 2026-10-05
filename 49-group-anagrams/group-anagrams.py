class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        Map={}
        for n in strs:
            l=list(n)
            l.sort()
            key="".join(l)
            if key not in Map:
                Map[key]=[]
            Map[key].append(n)
        return list(Map.values())