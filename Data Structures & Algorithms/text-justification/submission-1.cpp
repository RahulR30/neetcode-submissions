class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int counter = 0;
        vector<string> result;
        vector<string> lineWords;

        for (const auto& word : words) {

            if (counter + lineWords.size() + word.length() > maxWidth) {

                string line_output = "";

                if (lineWords.size() == 1) {
                    line_output = lineWords[0];
                    line_output.append(maxWidth - line_output.size(), ' ');
                } 
                else {
                    int available_spaces = maxWidth - counter;
                    int padding = available_spaces / (lineWords.size() - 1);
                    int padding_remainder = available_spaces % (lineWords.size() - 1);

                    for (int i = 0; i < lineWords.size(); i++) {
                        line_output += lineWords[i];

                        if (i < lineWords.size() - 1) {
                            line_output.append(padding, ' ');

                            if (padding_remainder > 0) {
                                line_output.push_back(' ');
                                padding_remainder--;
                            }
                        }
                    }
                }

                result.push_back(line_output);

                lineWords.clear();
                counter = 0;
            }

            lineWords.push_back(word);
            counter += word.length();
        }

        // Last line: left justified
        string lastLine = "";

        for (int i = 0; i < lineWords.size(); i++) {
            lastLine += lineWords[i];

            if (i < lineWords.size() - 1) {
                lastLine += " ";
            }
        }

        lastLine.append(maxWidth - lastLine.size(), ' ');
        result.push_back(lastLine);

        return result;
    }
};