#ifndef RESTRICTION_H
#define RESTRICTION_H

#include <regex>
#include <unordered_set>

namespace PasswordGuesstimator {

  class Restriction {
  public:
    virtual auto character_set() -> const std::unordered_set<char> & = 0;
    virtual auto character_set_size() -> uint64_t                    = 0;
    virtual auto character_set_regex() -> const std::regex         & = 0;
  };

  class PrintableAscii: public Restriction {
  public:
    // ASCII codes 32 to 126 are printable
    static inline const std::unordered_set<char> CHARACTER_SET = {
        ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',',  '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', ':', ';', '<', '=', '>', '?',  '@', 'A', 'B', 'C', 'D',  'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',  'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',  'p', 'q', 'r', 's', 't',  'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    };
    static inline const std::regex PRINTABLE_ASCII_REGEX = std::regex("[ -~]+");

    inline auto character_set() -> const std::unordered_set<char> & override {
      return CHARACTER_SET;
    }
    inline auto character_set_size() -> uint64_t override {
      return CHARACTER_SET.size();
    }
    inline auto character_set_regex() -> const std::regex & override {
      return PRINTABLE_ASCII_REGEX;
    }
  };

  class Alpha: public Restriction {
  public:
    static inline const std::unordered_set<char> CHARACTER_SET = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    };
    static inline const std::regex ALPHA_REGEX = std::regex("[a-zA-Z]");

    inline auto character_set() -> const std::unordered_set<char> & override {
      return CHARACTER_SET;
    }
    inline auto character_set_size() -> uint64_t override {
      return CHARACTER_SET.size();
    }
    inline auto character_set_regex() -> const std::regex & override {
      return ALPHA_REGEX;
    }
  };

  class Numeric: public Restriction {
  public:
    static inline const std::unordered_set<char> CHARACTER_SET = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    };
    static inline const std::regex NUMERIC_REGEX = std::regex("[0-9]+");

    inline auto character_set() -> const std::unordered_set<char> & override {
      return CHARACTER_SET;
    }
    inline auto character_set_size() -> uint64_t override {
      return CHARACTER_SET.size();
    }
    inline auto character_set_regex() -> const std::regex & override {
      return NUMERIC_REGEX;
    }
  };

  class AlphaNumeric: public Restriction {
  public:
    static inline const std::unordered_set<char> CHARACTER_SET = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    };
    static inline const std::regex ALPHANUMERIC_REGEX = std::regex("[a-zA-Z0-9]");

    inline auto character_set() -> const std::unordered_set<char> & override {
      return CHARACTER_SET;
    }
    inline auto character_set_size() -> uint64_t override {
      return CHARACTER_SET.size();
    }
    inline auto character_set_regex() -> const std::regex & override {
      return ALPHANUMERIC_REGEX;
    }
  };

} // namespace PasswordGuesstimator

#endif