function lengthOfLongestSubstring(s: string): number {
    const len: number = s.length;
    let max: number = 0;
    let strStartIdx: number = 0;
    let strEndIdx: number = 0;
    const set: Set<string> = new Set();

    while (strStartIdx < len && strEndIdx < len) {
        if (!set.has(s[strEndIdx])) {
            set.add(s[strEndIdx]);
            strEndIdx++;
            const newMax = strEndIdx - strStartIdx;
            max = max >= newMax ? max : newMax;
        } else {
            set.delete(s[strStartIdx]);
            strStartIdx++;
        }
    }

    return max;
}
