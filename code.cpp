vector<vector<string>> minimizeCashFlow(vector<vector<string>>& transactions) {
  unordered_map<string, long long> balance;

  for (auto& t : transactions) {

  long long amount = stoll(t[2]);

   balance[t[0]] -= amount;
   balance[t[1]] += amount;
    }

vector<pair<string, long long>> debtors;
vector<pair<string, long long>> creditors;

for (auto& p : balance) {
        if (p.second < 0)
            debtors.push_back({p.first, -p.second});
        else if (p.second > 0)
            creditors.push_back({p.first, p.second});
    }

vector<vector<string>> result;

int i = 0, j = 0;

while (i < debtors.size() && j < creditors.size()) {
long long amount = min(debtors[i].second, creditors[j].second);
result.push_back({
            debtors[i].first,
            creditors[j].first,
            to_string(amount)
        });

debtors[i].second -= amount;
creditors[j].second -= amount;

if (debtors[i].second == 0) i++;
if (creditors[j].second == 0) j++;
    }

return result;
}
