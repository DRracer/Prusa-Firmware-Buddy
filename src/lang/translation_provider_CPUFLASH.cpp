#include "string_view_utf8.hpp"
#include "translation_provider.hpp"
#include "string_hash.hpp"
#include "translator.hpp"
#include "translation_provider_CPUFLASH.hpp"

using TPBSH = CPUFLASHTranslationProviderBase::SHashTable;
#ifndef TRANSLATIONS_UNITTEST
const
#endif
    TPBSH CPUFLASHTranslationProviderBase::hash_table;

#ifndef TRANSLATIONS_UNITTEST
template <>
const TPBSH::BucketRange TPBSH::hash_table[TPBSH::Buckets()] =
    #include "hash_table_buckets.ipp"

    template <>
    const TPBSH::BucketItem TPBSH::stringRecArray[TPBSH::MaxStrings()] =
    #include "hash_table_string_indices.ipp"
#endif

        /// Wrappers of statically precomputed translation data for each language
    struct StringTableCS {
    // this will get statically precomputed for each translation language separately
    static const uint16_t stringBegins[];
    // a piece of memory where the null-terminated strings are situated
    static const uint8_t utf8Raw[];
};

struct StringTablePL {
    // this will get statically precomputed for each translation language separately
    static const uint16_t stringBegins[];
    // a piece of memory where the null-terminated strings are situated
    static const uint8_t utf8Raw[];
};

struct StringTableES {
    // this will get statically precomputed for each translation language separately
    static const uint16_t stringBegins[];
    // a piece of memory where the null-terminated strings are situated
    static const uint8_t utf8Raw[];
};

struct StringTableFR {
    // this will get statically precomputed for each translation language separately
    static const uint16_t stringBegins[];
    // a piece of memory where the null-terminated strings are situated
    static const uint8_t utf8Raw[];
};

struct StringTableDE {
    // this will get statically precomputed for each translation language separately
    static const uint16_t stringBegins[];
    // a piece of memory where the null-terminated strings are situated
    static const uint8_t utf8Raw[];
};

struct StringTableIT {
    // this will get statically precomputed for each translation language separately
    static const uint16_t stringBegins[];
    // a piece of memory where the null-terminated strings are situated
    static const uint8_t utf8Raw[];
};

using CPUFLASHTranslationProviderCS = CPUFLASHTranslationProvider<StringTableCS>;
using CPUFLASHTranslationProviderPL = CPUFLASHTranslationProvider<StringTablePL>;
using CPUFLASHTranslationProviderES = CPUFLASHTranslationProvider<StringTableES>;
using CPUFLASHTranslationProviderFR = CPUFLASHTranslationProvider<StringTableFR>;
using CPUFLASHTranslationProviderDE = CPUFLASHTranslationProvider<StringTableDE>;
using CPUFLASHTranslationProviderIT = CPUFLASHTranslationProvider<StringTableIT>;

// precomputed indices and strings for the CS(CZ) language
#include "stringBegins.cs.hpp"
#include "utf8Raw.cs.hpp"
template <>
const CPUFLASHTranslationProviderCS::RawData CPUFLASHTranslationProviderCS::rawData;

// precomputed indices and strings for the DE language
#include "stringBegins.de.hpp"
#include "utf8Raw.de.hpp"
template <>
const CPUFLASHTranslationProviderDE::RawData CPUFLASHTranslationProviderDE::rawData;

// precomputed indices and strings for the ES language
const uint16_t StringTableES::stringBegins[] = { 1, 2, 3, 4 };
// #include "stringBegins.es.hpp"
const uint8_t StringTableES::utf8Raw[] = "abcd";
// #include "utf8Raw.es.hpp"
template <>
const CPUFLASHTranslationProviderES::RawData CPUFLASHTranslationProviderES::rawData;

// precomputed indices and strings for the FR language
#include "stringBegins.fr.hpp"
#include "utf8Raw.fr.hpp"
template <>
const CPUFLASHTranslationProviderFR::RawData CPUFLASHTranslationProviderFR::rawData;

// precomputed indices and strings for the IT language
#include "stringBegins.it.hpp"
#include "utf8Raw.it.hpp"
template <>
const CPUFLASHTranslationProviderIT::RawData CPUFLASHTranslationProviderIT::rawData;

// precomputed indices and strings for the PL language
#include "stringBegins.pl.hpp"
#include "utf8Raw.pl.hpp"
template <>
const CPUFLASHTranslationProviderPL::RawData CPUFLASHTranslationProviderPL::rawData;

namespace {
static const CPUFLASHTranslationProviderCS cs;
ProviderRegistrator csReg("cs", &cs);

static const CPUFLASHTranslationProviderDE de;
ProviderRegistrator deReg("de", &de);

static const CPUFLASHTranslationProviderES es;
ProviderRegistrator esReg("es", &es);

static const CPUFLASHTranslationProviderFR fr;
ProviderRegistrator frReg("fr", &fr);

static const CPUFLASHTranslationProviderIT it;
ProviderRegistrator itReg("it", &it);

static const CPUFLASHTranslationProviderPL pl;
ProviderRegistrator plReg("pl", &pl);
}
