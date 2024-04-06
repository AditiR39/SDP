class Solution:
    def groupAnagrams(self, strs):
        ana=defaultdict(list)
        for words in strs:
            sort=''.join(sorted(words))
            ana[sort].append(words)
        return list(ana.values())