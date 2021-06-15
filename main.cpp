#include "main.h"

int main()
{

	Testing::TestingBigIntAdd(100000, false);

	Testing::TestingBigIntSub(100000, false);

	Testing::TestingBigIntAssignmentOperator(100000, false);

	Testing::TestingBigIntAdditionOperator(100000, false);
	Testing::TestingBigIntSubtractionOperator(100000, false);
	Testing::TestingBigIntPrefixIncrementOperator(100000, false);
	Testing::TestingBigIntPostfixIncrementOperator(100000, false);
	Testing::TestingBigIntPrefixDecrementOperator(100000, false);
	Testing::TestingBigIntPostfixDecrementOperator(100000, false);

	Testing::TestingBigIntAdditionAssessmentOperator(100000, false);
	Testing::TestingBigIntSubtractionAssessmentOperator(100000, false);
	Testing::TestingBigIntEqualComparisonOperator(100000, false);
	Testing::TestingBigIntNotEqualComparisonOperator(100000, false);

	Testing::TestingBigIntLessThanComparisonOperator(100000, false);
	Testing::TestingBigIntGreaterThanComparisonOperator(100000, false);
	Testing::TestingBigIntLessThanOrEqualComparisonOperator(100000, false);
	Testing::TestingBigIntGreaterThanOrEqualComparisonOperator(100000, false);
	
	Testing::TestingBigIntMultiplication(100000, false);

	Testing::TestingBigIntDivision(100000, false);
	Testing::TestingBigIntDivisionRandom(100000, false);

	Testing::TestingBigIntModulus(100000, false);
	Testing::TestingBigIntModulusRandom(100000, false);

	Testing::TestingBigIntMathTiming(100000, false);

	return 0;

}