BigInt add(BigInt a, BigInt b)
{
    // c sẽ là kết quả của phép tính c = a + b
    BigInt c;
    // Số chữ số của c sẽ lớn hơn hoặc bằng số chữ số lớn hơn của a hoặc b
    if (a.Digit.size() > b.Digit.size())
    {
        b.Digit.resize(a.Digit.size());
        c.Digit.resize(a.Digit.size());
    }
    else
    {
        a.Digit.resize(b.Digit.size());
        c.Digit.resize(b.Digit.size());
    }
    int leftover = 0; // đây là biến lưu số dư khi cộng hai chữ số
    for (int i = 0; i < c.Digit.size(); i++)
    {
        leftover = leftover + a.Digit[i] + b.Digit[i];
        c.Digit[i] = leftover % BASE;
        leftover = leftover / BASE;
    }
    // Nếu khi đã cộng xong mà leftover còn lớn hơn 0, ta sẽ bổ sung số đó vào đầu c
    if (leftover > 0)
    {
        c.Digit.push_back(leftover);
    }
    return c;
}
