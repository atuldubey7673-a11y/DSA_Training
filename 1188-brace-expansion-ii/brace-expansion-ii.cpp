class Solution {
public:

    // Parse a complete expression until '}' or end
    set<string> parse(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            // Comma -> union
            if (s[i] == ',') {
                result.insert(current.begin(), current.end());
                current = {""};
                i++;
            }

            // Opening brace
            else if (s[i] == '{') {
                i++;  // skip '{'

                set<string> inside = parse(s, i);

                i++;  // skip '}'

                current = multiply(current, inside);
            }

            // Normal character
            else {
                set<string> single;
                single.insert(string(1, s[i]));

                current = multiply(current, single);

                i++;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    // Cartesian product = concatenation
    set<string> multiply(set<string>& a, set<string>& b) {

        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};