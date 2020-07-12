package triangle

import "testing"

func TestGetTriangleType(t *testing.T) {
	type Test struct {
		a, b, c  int
		expected triangleType
	}

	var tests = []Test{
		{1001, 5, 6, UnknownTriangle},
		{5, 2001, 6, UnknownTriangle},
		{6, 5, 3001, UnknownTriangle},
		{0, 5, 6, UnknownTriangle},
		{5, 0, 6, UnknownTriangle},
		{6, 5, 0, UnknownTriangle},
		{1,2,3,InvalidTriangle},
		{3,4,5,RightTriangle},
		{4,4,5,AcuteTriangle},
		{3,3,5,ObtuseTriangle},
		// TODO add more tests for 100% test coverage
	}

	for _, test := range tests {
		actual := getTriangleType(test.a, test.b, test.c)
		if actual != test.expected {
			t.Errorf("getTriangleType(%d, %d, %d)=%v; want %v", test.a, test.b, test.c, actual, test.expected)
		}
	}
}
