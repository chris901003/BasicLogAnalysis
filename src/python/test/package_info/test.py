import pytest
import random

from PackageInfoTest import FilePackageInfoData, WebViewPackageInfoData, LivePackageInfoData

class TestPackageInfo:
    def test_file_package_info_data(self):
        # Test 5 times
        for _ in range(5):
            random_number = random.randint(3000, 5000)
            file_package_info_data = FilePackageInfoData(1, random_number)
            package_size_cnt = 0
            while True:
                package_info_data = file_package_info_data.generatePackage()
                package_size = package_info_data.packetSize
                package_size_cnt += package_size
                if package_size_cnt == random_number:
                    break
                assert 1000 <= package_size <= 1500, "生成值不在範圍內"
            assert package_size_cnt == random_number, "總和不等於隨機數值"
    
    def test_web_package_info_data(self):
        # Test 1000 times
        first_package_large_cnt = 0
        first_package_small_cnt = 0

        for _ in range(1000):
            random_number = random.randint(10000, 15000)
            web_package_info_data = WebViewPackageInfoData(1, random_number)
            package_size_cnt = 0
            while True:
                package_info_data = web_package_info_data.generatePackage()
                package_size = package_info_data.packetSize
                if package_size_cnt == 0:
                    if package_size_cnt == random_number:
                        break
                    if package_size >= 1000:
                        first_package_large_cnt += 1
                    else:
                        first_package_small_cnt += 1
                package_size_cnt += package_size
                if package_size_cnt == random_number:
                    break
                assert 100 <= package_size <= 1500, "生成值不在範圍內"
            assert package_size_cnt == random_number, "總和不等於隨機數值"

        assert first_package_large_cnt > first_package_small_cnt, "大包比例不對"
        total_package_cnt = first_package_large_cnt + first_package_small_cnt
        assert abs(first_package_large_cnt / total_package_cnt - 0.8) < 0.1, "大包比例不對"
    
    def test_live_package_info_data(self):
        for _ in range(5):
            random_number = random.randint(3000, 5000)
            live_package_info_data = LivePackageInfoData(1, random_number)
            package_size_cnt = 0
            while True:
                package_info_data = live_package_info_data.generatePackage()
                package_size = package_info_data.packetSize
                package_size_cnt += package_size
                if package_size_cnt == random_number:
                    break
                assert 100 <= package_size <= 800, "生成值不在範圍內"
            assert package_size_cnt == random_number, "總和不等於隨機數值"
