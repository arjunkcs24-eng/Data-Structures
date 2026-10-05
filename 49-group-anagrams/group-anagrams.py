class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        Map={}
        for n in strs:
            key="".join(sorted(n))
            if key not in Map:
                Map[key]=[]
            Map[key].append(n)
        return list(Map.values())