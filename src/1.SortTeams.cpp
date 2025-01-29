// Ranking drużyn na podstawie listy ich punktów
// Wypisz posortowaną listę z zsumowaną liczbą punktów
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

typedef std::map<std::string, std::list<int>> MapOfTeams;
typedef std::pair<std::string, int> PairStringInt;

std::vector<PairStringInt> createRanking(const MapOfTeams& teams)
{
    std::vector<PairStringInt> points;
    for (const auto& team : teams) {
        auto sum = std::accumulate(team.second.begin(), team.second.end(), 0);
        points.push_back(std::make_pair(team.first, sum));
    }

    std::sort(points.begin(), points.end(), [](const PairStringInt& a, const PairStringInt& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    return points;
}

int main(){
    MapOfTeams team_points = {
        {"Drużyna A", {10, 20, 30}},
        {"Drużyna B", {20, 10, 10}},
        {"Drużyna C", {15, 15, 15}},
        {"Drużyna D", {30, 30, 30}}
    };

    auto ranking = createRanking(team_points);

    for (const auto& team : ranking)
        std::cout << team.first << " - " << team.second << " points" << std::endl;

    return 0;
}