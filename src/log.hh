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

/* Log severities */
enum LogSeverity {
    Error,
    Info,
    Debug
};

inline const char *severityToString(LogSeverity s) {
    switch(s) {
        case Error:
            return "Error";
            break;
        case Info:
            return "Info";
            break;
        case Debug:
            return "Debug";
            break;
        default:
            return "!";
            break;
    };
}

/* Log function */
void log(LogSeverity, const char *);
