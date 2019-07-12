BigInt mulInt(BigInt a, int b) {
    BigInt c;
    // Đặt số lượng chữ số của c bằng của a
    c.Digit.resize(a.Digit.size());
    int leftover = 0;
    for (int i = 0; i < c.Digit.size(); i++) {
    // Duyệt qua từng chữ số của a từ hàng đơn vị lên và tính
        leftover = leftover + a.Digit[i] * b;
        c.Digit[i] = leftover % BASE;
        leftover = leftover / BASE;
    }
    // trường hợp số dư còn lớn hơn 0, ta phải thêm vào đầu kết quả
    while (leftover > 0) {
        c.Digit.push_back(leftover % BASE);
        leftover = leftover / BASE;
    }
    // Trường hợp b = 0, ta phải xóa các chữ số 0 vô nghĩa
    while (c.Digit.size() >= 2 && c.Digit.back() == 0)
        c.Digit.pop_back();
    return c;
}
BigInt mul(BigInt a, BigInt b) {
    BigInt c;
    // khai báo số lượng chữ số của kết quả a*b
    c.Digit.resize(a.Digit.size() + b.Digit.size() + 2);
    // lấy từng chữ số của b nhân với a
    for (int i = 0; i < b.Digit.size(); i++) {        // luôn luôn khởi tạo biến dư đầu mỗi lần nhân bằng 0
        int leftover = 0;        // duyệt qua từng chữ số trong a
        for (int j = 0; j < a.Digit.size(); j++) {
            leftover = leftover + c.Digit[j + i] + b.Digit[i] * a.Digit[j];
            c.Digit[j + i] = leftover % BASE;
            leftover = leftover / BASE;
        }
        // vị trí của chữ số đầu tiên khi lấy số thứ i ra nhân với a
        int pos = i + a.Digit.size() - 1;
        while (leftover > 0) {
            leftover = leftover + c.Digit[++pos];
            c.Digit[pos] = leftover % BASE;
            leftover = leftover / BASE;
        }
    }
    // xóa bớt chữ số 0 ở đầu kết quả
    while (c.Digit.size() >= 2 && c.Digit.back() == 0)
        c.Digit.pop_back();
    return c;
}
