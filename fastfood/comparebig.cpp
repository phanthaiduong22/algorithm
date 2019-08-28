/* Hàm trả về -1 nếu a < b; 0 nếu a = b, 1 nếu a > b */
int compare(BigInt a, BigInt b) {
    if (a.Digit.size() > b.Digit.size()) return 1;
    else if (a.Digit.size() < b.Digit.size()) return -1;
    else {
        /* Nếu a, b có cùng số chữ số */
        if (a.Digit == b.Digit) return 0;
        else if (a.Digit < b.Digit) return -1;
        else return 1;
    }
}

int divSmall(BigInt &a, BigInt b) {
    BigInt tmp;
    // Sử dụng tìm kiếm nhị phân
    // d sẽ luôn thỏa mãn b * d < a, còn c thì không
    int d = 0, c = BASE, mid;
    while (d + 1 < c) {
        mid = (d + c) >> 1;
        tmp = mulInt(b, mid);
        if (compare(tmp, a) <= 0)
            d = mid;
        else
            c = mid;
    }
    // Tính kết quả b * d
    tmp = mulInt(b, d);
    // Lấy phần dư của phép chia
    a = sub(a, tmp);
    // Trả về chữ số ta tìm được
    return d;
}