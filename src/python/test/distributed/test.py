import pytest
from PoissonDistributedTest import PoissonDistributed

def test_gen_packet_count():
    avg_rate = 5.0
    poisson = PoissonDistributed(avg_rate)
    counts = [poisson.genPacketCount() for _ in range(1000)]

    # # 測試平均值是否接近 avg_rate
    assert abs(sum(counts) / len(counts) - avg_rate) < 0.5

    # # 測試產生的值是否為非負整數
    assert all(isinstance(count, int) and count >= 0 for count in counts)

