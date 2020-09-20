# store.project
-------------------------------
Thông tin nhóm:
    19127083 - Nguyễn Hữu Tuấn - 19127083@student.hcmus.edu.vn (Nhóm trưởng)
    19127100 - Lê Trần Gia Bảo - 19127100@student.hcmus.edu.vn
    19127352 - Hồ Vạn Đạt - 19127352@student.hcmus.edu.vn
    19127626 - Lê Nguyễn Tú Văn - 19127626@student.hcmus.edu.vn
Lớp 19CLC8, Khoa Công Nghệ Thông Tin, chương trình Chất lượng cao

TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN TP HỒ CHÍ MINH, KHOA CÔNG NGHỆ THÔNG TIN
-------------------------------
* Đồ án một hệ thống quản lý cửa hàng, dành cho người dùng, nhân viên và cả quản lí.
* Đồ án chia thành 2 phần lớn, là phần dành cho người dùng (nhân viên, quản lí và khách hàng) và phần tiện ích (xem thông tin, đánh giá và đăng kí thành viên)
* Đồ án do nhóm tự nghĩ ra, vui lòng ghi nguồn khi copy, reup
-------------------------------
* Tỉ lệ điểm:
    19127083 - 10
    19127100 - 7
    19127352 - 10
    19127626 - 10
- Điểm mong muốn: 9 (vì thiếu 3 chức năng chưa làm được)
- Điểm cộng (nếu có): 19127083, 19127352

-------------------------------
* Các chức năng chưa làm được:
    - Chuyển phát (Delivery)
    - Mua hàng với tư cách là khách lạ
    - Storage (Nguyên liệu)

-------------------------------
    ** Để chạy được code với Visual Studio Code: 
* Trước tiên để chạy được code, người dùng lưu ý phải giữ lại file .vscode và cài đặt MingW64. Sau đó dẫn đường dẫn đến gdb.exe trong file launch.json, phần "miDebuggerPath", đường dẫn đến g++.exe trong tasks.json, phần "command", và chỉnh "externalConsole" trong launch.json thành true
* Sau đó, dẫn đường dẫn tuyệt đối đến folder chứa code, cụ thể là trong folder Utility, file util.h
-------------------------------
* Sau khi chạy được chương trình, người dùng có thể đăng nhập dưới dạng quản lí, nhân viên hoặc hội viên
    - Đăng nhập quản lí dùng Username: tuan ; Password: 123
    - Đăng nhập nhân viên dùng Username(số điện thoại): 123 ; Password: 123
    - Đănh nhập hội viên dùng Username: tuan ; Password: 123

-------------------------------
* Về cấu trúc, lớp hàm về truy cập ở Menu chính sẽ nằm trong folder Console, xem qua file interface.h và Menu.h để hiểu thêm về cấu trúc
    - Gồm 2 nhóm chính là lớp hàm đăng nhập và lớp hàm tiện ích
    - Thiết kế Menu theo nguyên tắc switch-case để chọn nằm trong vòng lặp do-while, khi quay lại thì break vòng lặp để hàm kết thúc.
    - Thông tin cài đặt cụ thể về từng lớp hàm được chia theo folder:
        + Bill_Order chứa cài đặt lớp hàm khi người mua Order hàng hoá.
        + Console chứa cài đặt về Menu và các hàm tiện ích khác khi đi sâu vào Menu
        + Discount chứa cài đặt về các thông tin khuyến mãi dành cho hội viên
        + Employee chứa cài đặt về nhân viên như thông tin, checkin-checkout,...
        + Good chứa cài đặt về hàng hoá và thông tin về hàng hoá
        + Member chứa cài đặt về hội viên và các hành động của hội viên như Mua hàng, xem (sửa) thông tin,...
        + Profit chứa cài đặt về cách tính lợi nhuận
        + System chứa cài đặt về quản lí, ví dụ như cách quản lí nhân viên, hội viên, và thu nhập của cửa hàng.