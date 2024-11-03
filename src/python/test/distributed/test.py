import pytest
import numpy as np

from DistributedTest import PoissonDistributed, NormalDistributed, UniformDistributed


class TestDistribution:

    def test_poisson_gen_packet_count(self):
        avg_rate = 5.0
        poisson = PoissonDistributed(avg_rate)
        counts = [poisson.genPacketCount() for _ in range(1000)]

        assert abs(sum(counts) / len(counts) - avg_rate) < 0.5

        assert all(isinstance(count, int) and count >= 0 for count in counts)
    
    def test_normal_gen_packet_count(self):
        mean = 10
        stddev = 5
        dist = NormalDistributed(mean, stddev)

        packet_counts = [dist.genPacketCount() for _ in range(1000)]
        assert all(count >= 0 for count in packet_counts), "Packet count should be non-negative"
        
        actual_mean = np.mean(packet_counts)
        actual_stddev = np.std(packet_counts)

        assert abs(actual_mean - mean) < 1, f"Mean should be close to {mean}"
        assert abs(actual_stddev - stddev) < 1, f"Standard deviation should be close to {stddev}"

    def test_uniform_gen_packet_count(self):
        min_val, max_val = 1, 10
        dist = UniformDistributed(min_val, max_val)
        
        for _ in range(100):
            count = dist.genPacketCount()
            assert min_val <= count <= max_val, "生成值不在範圍內"

        with pytest.raises(ValueError, match="Invalid range"):
            UniformDistributed(10, 5)  # max < min

        with pytest.raises(ValueError, match="Invalid range"):
            UniformDistributed(-1, 10)  # min < 0

        counts = {dist.genPacketCount() for _ in range(100)}
        assert len(counts) > 1, "生成值無變化，可能存在隨機性問題"
