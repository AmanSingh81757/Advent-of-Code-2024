    #include <bits/stdc++.h>
    using namespace std;

    int max_pattern_length;

    map<string, int> patternCount;
    map<string, int> designPossible;

    void takePatternsInput(vector<string> &available_patterns)
    {
        string line;
        getline(cin, line);
        int i = 0;
        string curr = "";
        while (i < line.length())
        {
            if (line[i] == ',')
            {
                available_patterns.push_back(curr);
                max_pattern_length = max(max_pattern_length, (int)curr.length());
                curr = "";
            }
            else if (line[i] != ' ')
            {
                curr += line[i];
            }
            i++;
        }
        max_pattern_length = max(max_pattern_length, (int)curr.length());
        available_patterns.push_back(curr);
    }

    void takeDesignsInput(vector<string> &wanted_designs)
    {
        string line;
        getline(cin, line);
        while (getline(cin, line))
        {
            wanted_designs.push_back(line);
        }
    }

    bool canMakeDesign(string &design)
    {
        int ans = 0;
        if(designPossible.find(design) != designPossible.end()){
            return designPossible[design];
        }

        int n = design.size();
        for(auto &it: patternCount){
            string pattern = it.first;
            int p = pattern.size();
            if(n < p){
                continue;
            }
            if(design.substr(0, p) == pattern){
                if(n == p){
                    return designPossible[design] = 1;
                }
                string rem = design.substr(p);
                ans |= canMakeDesign(rem);
                if(ans == 1)
                    return designPossible[design] = 1;
            }
        }
        return designPossible[design] = ans;
    }

    void solve()
    {
        vector<string> available_patterns;
        vector<string> wanted_designs;

        takePatternsInput(available_patterns);
        takeDesignsInput(wanted_designs);

        for (auto pattern : available_patterns)
        {
            patternCount[pattern]++;
        }

        int total_possibleDesigns = 0;
        for (auto &design : wanted_designs)
        {
            int can = canMakeDesign(design);
            total_possibleDesigns += can;
        }

        cout<<total_possibleDesigns<<endl;
    }

    int main()
    {
        clock_t start, end;
        double cpu_time_used;

        start = clock();

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

        solve();

        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "Time: " << cpu_time_used << endl;
    }