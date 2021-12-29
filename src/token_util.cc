/*
 * Copyright (c) 2021 Noah Vogt <noah@noahvogt.com>
 * Copyright (c) 2011 Matthew Iselin
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <map>
#include <string>
#include <string.h>

#include "token_util.hh"
#include "token_list.h"

using namespace std;

/* References to lists defined after functions. */

/* string -> token mapping */
map<string, token_t> g_TokenLookup;

/* token -> string mapping */
map<unsigned short, string> g_ReverseLookup;

/* Longest input string possible */
size_t g_LongestInput = 0;

/* Shiny little template function that returns the size of an array. */
template <typename T, int N> size_t arrayLen(T(&)[N]){return N;}

/* Initialises the token map */
void initialiseTokens() {
    /* Iterate the main token list first. */
    for(size_t i = 0; i < arrayLen(StandardTokens); i++) {
        token_t value;
        value.token = StandardTokens[i].data;
        value.sz = sizeof(StandardTokens[i].data);

        size_t len = strlen(StandardTokens[i].text);
        if(len > g_LongestInput)
            g_LongestInput = len;

        string s = string(StandardTokens[i].text);
        g_TokenLookup[s] = value;
        g_ReverseLookup[value.token] = s;
    }

    /* Now iterate the two-byte tokens. */
    for(size_t i = 0; i < (sizeof(CalcVars) / sizeof(Token)); i++) {
        token_t value;
        value.token = CalcVars[i].data;
        value.sz = sizeof(CalcVars[i].data);

        size_t len = strlen(CalcVars[i].text);
        if(len > g_LongestInput)
            g_LongestInput = len;
        
        string s = string(CalcVars[i].text);
        g_TokenLookup[s] = value;
        g_ReverseLookup[value.token] = s;
    }

    /* Finally, iterate single-character tokens. */
    for(size_t i = 0; i < (sizeof(Replacements) / sizeof(ConvertRule)); i++) {
        token_t value;
        value.token = Replacements[i].tok;
        value.sz = sizeof(Replacements[i].tok);

        char c[] = {Replacements[i].c, 0};
        string s = c;

        g_TokenLookup[s] = value;
        g_ReverseLookup[value.token] = s;
    }
}

size_t getLongestToken() {
    return g_LongestInput;
}

/* Perform a lookup */
bool lookupToken(string in, token_t &ret) {
    if(in.length() > g_LongestInput)
        return false;

    if(g_TokenLookup.find(in) == g_TokenLookup.end())
        return false;

    ret = g_TokenLookup[in];

    return true;
}

bool lookupToken(unsigned short in, string &out) {
    if(g_ReverseLookup.find(in) == g_ReverseLookup.end())
        return false;

    out = g_ReverseLookup[in];

    return true;
}
