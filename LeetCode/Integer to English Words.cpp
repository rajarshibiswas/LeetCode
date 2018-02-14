//
//  Integer to English Words.cpp
//  LeetCode - https://leetcode.com/problems/integer-to-english-words/description/
//
//  Created by Rajarshi Biswas on 2/13/18.
//  Copyright © 2018 Rajarshi Biswas. All rights reserved.
//
//
/*
    Convert a non-negative integer to its english word
    representation. Given input is guaranteed to be less than 2^31-1.
    For example,
 
    123 -> "One Hundred Twenty Three"
    12345 -> "Twelve Thousand Three Hundred Forty Five"
    1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include <stdio.h>
#include "common.h"

class Solution {
private:
    // Converts a maximum three digits number
    // to words
    string hundredstr(int num) {
        vector<string> arr1={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
            "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> arr2={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string result;
        result = (num % 100) < 20 ? arr1[num % 100] : arr2[(num % 100) / 10] + (num % 10 ? " " + arr1[num % 10]:"");
        if(num > 99) {
            result = arr1[num / 100] + " Hundred" + (num % 100 ? " " + result : "");
        }
        return result;
        
    }
public:
    string numberToWords(int num) {
        string result = "";
        vector <string> strarr = {"Thousand","Million", "Billion"};
        // Convert the first three digits to words first
        result = hundredstr (num%1000);
        for (int i = 0; i < 3; i++) {
            // Now go over thousand million
            // and billion
            num = num / 1000;
            result = num%1000? hundredstr(num % 1000) + " " + strarr[i] + " " + result : result;
        }
        while (result.back() ==  ' ') {
            result.pop_back();
        }
        return result.empty() ? "Zero" : result;
    }
};
