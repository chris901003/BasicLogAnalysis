import bind_test

def test_add():
    assert bind_test.add(3, 4) == 7
    assert bind_test.add(-1, 1) == 0
    assert bind_test.add(0, 0) == 0
