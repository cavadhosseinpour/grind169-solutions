#include <iostream>
#include <vector>

class Solution {
private:
    void helper_floodFill(std::vector<std::vector<int>>& image, int r, int c, const int color, const int original_color)
    {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != original_color) return;

        image[r][c] = color;
        helper_floodFill(image, r - 1, c, color, original_color);
        helper_floodFill(image, r + 1, c, color, original_color);
        helper_floodFill(image, r, c - 1, color, original_color);
        helper_floodFill(image, r, c + 1, color, original_color);
    }
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        int original_color = image[sr][sc];
        if (original_color != color)
        {
            helper_floodFill(image, sr, sc, color, original_color);
        }

        return image;
    }
};

int main()
{
    std::vector<std::vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    Solution sol;
    image = sol.floodFill(image, 1, 1, 2);
    for (int i = 0; i != image.size(); ++i)
    {
        for (int j = 0; j != image[0].size(); ++j)
        {
            std::cout << image[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}