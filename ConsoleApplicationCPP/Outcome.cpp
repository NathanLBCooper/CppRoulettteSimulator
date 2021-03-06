#include "stdafx.h"
#include <cstdint>
#include <string>
#include <memory>

#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Outcome"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="odds">The odds.</param>
	Outcome::Outcome(std::string name, std::int32_t odds)
		: name(name), odds(odds)
	{
		if (this->Odds < 0)
		{
			throw std::invalid_argument("Odds must be non-negative");
		}
	}

	/// <summary>
	/// Gets the Name (Use the property Name).
	/// Holds the name of the Outcome. Examples include "1", "Red".
	/// </summary>
	/// <returns>The Name</returns>
	std::string Outcome::GetName() const
	{
		return this->name;
	}

	/// <summary>
	/// Gets the Odds (Use the property Odds).
	/// Odds are stated as eg 17:1, we only keep the numerator(17).
	/// </summary>
	/// <returns>The Odds</returns>
	std::int32_t Outcome::GetOdds() const
	{
		return this->odds;
	}

	/// <summary>
	/// Caculate the Win Amount. The overall, including the returned stake.
	/// </summary>
	/// <param name="bet">The bet.</param>
	/// <returns>The win amount</returns>
	std::int32_t Outcome::WinAmount(std::int32_t betAmount)
	{
		if (betAmount < 0)
		{
			throw std::invalid_argument("Bet must be non-negative");
		}
		return (this->Odds * betAmount) + betAmount;
	}

	bool Outcome::operator==(const Outcome& outcomeOther) const
	{
		return (this->Name == outcomeOther.Name);
	}

	bool Outcome::operator!=(const Outcome& outcomeOther) const
	{
		return !(this->operator==(outcomeOther));
	}
}

namespace std {
	template <> 
	struct hash <ConsoleApplicationCpp::Outcome>
	{
		size_t operator()(const ConsoleApplicationCpp::Outcome & x) const
		{
			return hash<std::string>()(x.Name);
		}
	};
}