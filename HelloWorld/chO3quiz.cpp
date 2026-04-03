#include "chO3quiz.h"
#include <bitset>
#include <cstdint>
#include <iostream>

void chO3quiz()
{
	[[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
	[[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
	[[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04};
	[[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
	[[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

	std::uint8_t myArticleFlags{ option_favorited };

	// question a - set the article as viewed
	myArticleFlags |= option_viewed;

	std::cout << std::bitset<8>{ myArticleFlags } << '\n';

	// question b - check if the article was deleted
	// std::cout << (static_cast<bool>(myArticleFlags & option_deleted ) ? "yes deleted\n" : "not deleted\n");
	// std::cout << ((myArticleFlags & option_deleted) ? "yes\n" : "no\n");

	// question c - clear article from favorites
	myArticleFlags &= static_cast<std::uint8_t>(~option_favorited);

	std::cout << std::bitset<8>{ myArticleFlags } << '\n';
}