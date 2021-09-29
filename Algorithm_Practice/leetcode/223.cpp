class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rect1 = (ax2 - ax1) * (ay2 - ay1), rect2 = (bx2 - bx1) * (by2 - by1), rect_overlapping;
        int overlapping_width = min(ax2, bx2) - max(bx1, ax1), overlapping_height = min(ay2, by2) - max(ay1, by1);
        rect_overlapping = max(overlapping_width, 0) * max(overlapping_height, 0);
        return rect1 + rect2 - rect_overlapping;
    }
};