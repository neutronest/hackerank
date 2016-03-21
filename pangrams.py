#!/usr/bin/env
# -*- coding: utf-8 -*-

if __name__ == "__main__":
    char_map = {}
    last_num = 26
    s_input = raw_input()
    s = s_input.lower()
    s = s.replace(" ", "")
    len_s = len(s)
    for i in xrange(0, len_s):
        if(char_map.get(s[i]) == None):
            #print s[i]
            char_map[s[i]] = 1
            last_num -= 1
            #print last_num
    if (last_num == 0):
        print "pangram"
    else:
        print "not pangram"


