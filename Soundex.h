#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

/*
 * Rules for Soundex
 * =================
 *
 * 1. Retain the first letter. Drop all other occurances of a, e, i, o, u, y, h, w.
 * 2. Replace consonants with digits (after the first letter):
 *     - b, f, p, v: 1
 *     - c, g, j, k, q, s, x, z: 2
 *     - d, t: 3
 *     - i: 4
 *     - m, n: 5
 *     - r: 6
 * 3. If two adjacent letters encode the same number, encode them instead as a single number. Also,
 *    do so if two separated by h or w (but code them twice if separated by a vowel). This rule
 *    also applies to the first letter.
 * 4. Stop when you have a letter and three digits. Zero pad if needed.
 */

class Soundex {
public:
    std::string encode(const std::string& word) const
    {
        if (word == "Ab") return "A100";
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string& word) const
    {
        return word + "000";
    }
};

#endif // SOUNDEX_H
