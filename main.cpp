#include "main.h"

int main()
{

	Testing::TestingBigIntAdd(1000, false);

	Testing::TestingBigIntSub(1000, false);

	Testing::TestingBigIntAssignmentOperator(1000, false);

	Testing::TestingBigIntAdditionOperator(1000, false);
	Testing::TestingBigIntSubtractionOperator(1000, false);
	Testing::TestingBigIntPrefixIncrementOperator(1000, false);
	Testing::TestingBigIntPostfixIncrementOperator(1000, false);
	Testing::TestingBigIntPrefixDecrementOperator(1000, false);
	Testing::TestingBigIntPostfixDecrementOperator(1000, false);

	Testing::TestingBigIntAdditionAssessmentOperator(1000, false);
	Testing::TestingBigIntSubtractionAssessmentOperator(1000, false);
	Testing::TestingBigIntEqualComparisonOperator(1000, false);
	Testing::TestingBigIntNotEqualComparisonOperator(1000, false);

	Testing::TestingBigIntLessThanComparisonOperator(1000, false);
	Testing::TestingBigIntGreaterThanComparisonOperator(1000, false);
	Testing::TestingBigIntLessThanOrEqualComparisonOperator(1000, false);
	Testing::TestingBigIntGreaterThanOrEqualComparisonOperator(1000, false);
	
	Testing::TestingBigIntMultiplication(1000, false);

	Testing::TestingBigIntDivision(1000, false);
	Testing::TestingBigIntDivisionRandom(1000, false);

	Testing::TestingBigIntModulus(1000, false);
	Testing::TestingBigIntModulusRandom(1000, false);

	Testing::TestingBigIntMathTiming(1000, false);

	return 0;

}