#pragma once
#include <unordered_map>
#include <string>
class Resource {
private:
    int amount = 0;
    std::string name;
public:
    static std::unordered_map<std::string, int> resourceCounter;
    Resource( std::string name, int amount):amount(amount), name(name) {
        if (resourceCounter.find(name) != resourceCounter.end())
            resourceCounter[name] = 0;
        resourceCounter[name] += amount;
    }
    Resource() {};
    const int& getAmount() const {
        return amount;
    }
    Resource& operator+=(int addAmount) {
        amount += addAmount;
        resourceCounter[name] += amount;
        return *this;
    }
    Resource& operator-=(int addAmount) {
        resourceCounter[name] -= addAmount;
        amount -= addAmount;
        return *this;
    }
};

