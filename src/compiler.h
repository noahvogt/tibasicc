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

#include <string>

#ifdef _MSC_VER
#define PACKED
#else
#define PACKED __attribute__((packed))
#endif

/* Compilation class. */
class Compiler {
    public:
        Compiler() {}
        virtual ~Compiler() {}

        bool compile(std::string inFile, std::string outFile);

        bool decompile(std::string inFile, std::string outFile);

    private:
        /* Perform a checksum over a region of data. */
        size_t sumBytes(const char *data, size_t len);
        unsigned short doChecksum(size_t sum);

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif

        /* 8xp file header */
        struct ProgramHeader {
            char sig[9];
            char extsig[3];
            char comment[42];
            unsigned short datalen;
        } PACKED;

        /* Variable entry */
        struct VariableEntry {
            unsigned short start;
            unsigned short length1;
            unsigned char type;
            char name[8];
            char ver;
            char flags;
            unsigned short length2;
        } PACKED;

#ifdef _MSC_VER
#pragma pack(pop)
#endif
};
