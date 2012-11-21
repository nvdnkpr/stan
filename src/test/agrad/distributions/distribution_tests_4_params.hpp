#ifndef __TEST__AGRAD__DISTRIBUTIONS__DISTRIBUTION_TESTS_4_PARAMS_HPP___
#define __TEST__AGRAD__DISTRIBUTIONS__DISTRIBUTION_TESTS_4_PARAMS_HPP___

// v: var
// d: double
// V: vector<var>
// D: vector<double>
template<class T0, class T1, class T2, class T3,
	 class T4, class T5, class T6,
	 class T7, class T8, class T9>
class CALL_LOG_PROB {
public:
  var call(T0& p0, T1& p1, T2& p2, T3& p3, T4&, T5&, T6&, T7&, T8&, T9&) {
    return _LOG_PROB_<true>(p0, p1, p2, p3);
  }
  var call_nopropto(T0& p0, T1& p1, T2& p2, T3& p3, T4&, T5&, T6&, T7&, T8&, T9&) {
    return _LOG_PROB_<false>(p0, p1, p2, p3);
  }
};

TYPED_TEST_P(AgradDistributionTestFixture, call_all_versions) {
  vector<double> parameters = this->first_valid_params();
  ASSERT_EQ(parameters.size(), 4U);

  var param1, param2, param3, param4;
  var logprob;
  param1 = parameters[0];
  param2 = parameters[1];
  param3 = parameters[2];
  param4 = parameters[3];
  
  EXPECT_NO_THROW(logprob = _LOG_PROB_<true>(param1, param2, param3, param4));
  EXPECT_NO_THROW(logprob = _LOG_PROB_<false>(param1, param2, param3, param4));
  EXPECT_NO_THROW(logprob = _LOG_PROB_<true>(param1, param2, param3, param4, errno_policy()));
  EXPECT_NO_THROW(logprob = _LOG_PROB_<false>(param1, param2, param3, param4, errno_policy()));
  EXPECT_NO_THROW(logprob = _LOG_PROB_(param1, param2, param3, param4));
  EXPECT_NO_THROW(logprob = _LOG_PROB_(param1, param2, param3, param4, errno_policy()));
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_dddd) {
  test_valid<TypeParam, double, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_dddv) {
  test_valid<TypeParam, double, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_ddvd) {
  test_valid<TypeParam, double, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_ddvv) {
  test_valid<TypeParam, double, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_dvdd) {
  test_valid<TypeParam, double, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_dvdv) {
  test_valid<TypeParam, double, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_dvvd) {
  test_valid<TypeParam, double, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_dvvv) {
  test_valid<TypeParam, double, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vddd) {
  test_valid<TypeParam, var, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vddv) {
  test_valid<TypeParam, var, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vdvd) {
  test_valid<TypeParam, var, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vdvv) {
  test_valid<TypeParam, var, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vvdd) {
  test_valid<TypeParam, var, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vvdv) {
  test_valid<TypeParam, var, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vvvd) {
  test_valid<TypeParam, var, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_valid_vvvv) {
  test_valid<TypeParam, var, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_dddd) {
  test_invalid<TypeParam, double, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_dddv) {
  test_invalid<TypeParam, double, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_ddvd) {
  test_invalid<TypeParam, double, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_ddvv) {
  test_invalid<TypeParam, double, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_dvdd) {
  test_invalid<TypeParam, double, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_dvdv) {
  test_invalid<TypeParam, double, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_dvvd) {
  test_invalid<TypeParam, double, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_dvvv) {
  test_invalid<TypeParam, double, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vddd) {
  test_invalid<TypeParam, var, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vddv) {
  test_invalid<TypeParam, var, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vdvd) {
  test_invalid<TypeParam, var, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vdvv) {
  test_invalid<TypeParam, var, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vvdd) {
  test_invalid<TypeParam, var, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vvdv) {
  test_invalid<TypeParam, var, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vvvd) {
  test_invalid<TypeParam, var, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture, check_invalid_vvvv) {
  test_invalid<TypeParam, var, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_dddd) {
  test_propto<TypeParam, double, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_dddv) {
  test_propto<TypeParam, double, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_ddvd) {
  test_propto<TypeParam, double, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_ddvv) {
  test_propto<TypeParam, double, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_dvdd) {
  test_propto<TypeParam, double, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_dvdv) {
  test_propto<TypeParam, double, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_dvvd) {
  test_propto<TypeParam, double, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_dvvv) {
  test_propto<TypeParam, double, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vddd) {
  test_propto<TypeParam, var, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vddv) {
  test_propto<TypeParam, var, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vdvd) {
  test_propto<TypeParam, var, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vdvv) {
  test_propto<TypeParam, var, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vvdd) {
  test_propto<TypeParam, var, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vvdv) {
  test_propto<TypeParam, var, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vvvd) {
  test_propto<TypeParam, var, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, logprob_propto_vvvv) {
  test_propto<TypeParam, var, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_dddd) {
  test_finite_diff<TypeParam, double, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_dddv) {
  test_finite_diff<TypeParam, double, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_ddvd) {
  test_finite_diff<TypeParam, double, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_ddvv) {
  test_finite_diff<TypeParam, double, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_dvdd) {
  test_finite_diff<TypeParam, double, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_dvdv) {
  test_finite_diff<TypeParam, double, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_dvvd) {
  test_finite_diff<TypeParam, double, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_dvvv) {
  test_finite_diff<TypeParam, double, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vddd) {
  test_finite_diff<TypeParam, var, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vddv) {
  test_finite_diff<TypeParam, var, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vdvd) {
  test_finite_diff<TypeParam, var, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vdvv) {
  test_finite_diff<TypeParam, var, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vvdd) {
  test_finite_diff<TypeParam, var, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vvdv) {
  test_finite_diff<TypeParam, var, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vvvd) {
  test_finite_diff<TypeParam, var, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_finite_diff_vvvv) {
  test_finite_diff<TypeParam, var, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_dddd) {
  test_gradient_function<TypeParam, double, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_dddv) {
  test_gradient_function<TypeParam, double, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_ddvd) {  
  test_gradient_function<TypeParam, double, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_ddvv) {  
  test_gradient_function<TypeParam, double, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_dvdd) {  
  test_gradient_function<TypeParam, double, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_dvdv) {  
  test_gradient_function<TypeParam, double, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_dvvd) {  
  test_gradient_function<TypeParam, double, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_dvvv) {  
  test_gradient_function<TypeParam, double, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vddd) {
  test_gradient_function<TypeParam, var, double, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vddv) {
  test_gradient_function<TypeParam, var, double, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vdvd) {  
  test_gradient_function<TypeParam, var, double, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vdvv) {  
  test_gradient_function<TypeParam, var, double, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vvdd) {  
  test_gradient_function<TypeParam, var, var, double, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vvdv) {  
  test_gradient_function<TypeParam, var, var, double, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vvvd) {  
  test_gradient_function<TypeParam, var, var, var, double>();
}
TYPED_TEST_P(AgradDistributionTestFixture2, gradient_function_vvvv) {  
  test_gradient_function<TypeParam, var, var, var, var>();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dddd) {
  test_vectorized<TypeParam, double, double, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dddD) {
  test_vectorized<TypeParam, double, double, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dddv) {
  test_vectorized<TypeParam, double, double, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dddV) {
  test_vectorized<TypeParam, double, double, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddDd) {
 test_vectorized<TypeParam, double, double, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddDD) {
  test_vectorized<TypeParam, double, double, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddDv) {
  test_vectorized<TypeParam, double, double, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddDV) {
  test_vectorized<TypeParam, double, double, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddvd) {
  test_vectorized<TypeParam, double, double, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddvD) {
  test_vectorized<TypeParam, double, double, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddvv) {
  test_vectorized<TypeParam, double, double, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddvV) {
  test_vectorized<TypeParam, double, double, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddVd) {
  test_vectorized<TypeParam, double, double, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddVD) {
  test_vectorized<TypeParam, double, double, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddVv) {
  test_vectorized<TypeParam, double, double, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_ddVV) {
  test_vectorized<TypeParam, double, double, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDdd) {
  test_vectorized<TypeParam, double, vector<double>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDdD) {
  test_vectorized<TypeParam, double, vector<double>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDdv) {
  test_vectorized<TypeParam, double, vector<double>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDdV) {
  test_vectorized<TypeParam, double, vector<double>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDDd) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDDD) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDDv) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDDV) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDvd) {
  test_vectorized<TypeParam, double, vector<double>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDvD) {
  test_vectorized<TypeParam, double, vector<double>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDvv) {
  test_vectorized<TypeParam, double, vector<double>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDvV) {
  test_vectorized<TypeParam, double, vector<double>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDVd) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDVD) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDVv) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dDVV) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVdd) {
  test_vectorized<TypeParam, double, vector<double>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVdD) {
  test_vectorized<TypeParam, double, vector<double>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVdv) {
  test_vectorized<TypeParam, double, vector<double>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVdV) {
  test_vectorized<TypeParam, double, vector<double>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVDd) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVDD) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVDv) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVDV) {
  test_vectorized<TypeParam, double, vector<double>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVvd) {
  test_vectorized<TypeParam, double, vector<double>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVvD) {
  test_vectorized<TypeParam, double, vector<double>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVvv) {
  test_vectorized<TypeParam, double, vector<double>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVvV) {
  test_vectorized<TypeParam, double, vector<double>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVVd) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVVD) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVVv) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture3, vectorized_dVVV) {
  test_vectorized<TypeParam, double, vector<double>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_Dddd) {
  test_vectorized<TypeParam, vector<double>, double, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DddD) {
  test_vectorized<TypeParam, vector<double>, double, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_Dddv) {
  test_vectorized<TypeParam, vector<double>, double, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DddV) {
  test_vectorized<TypeParam, vector<double>, double, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdDd) {
  test_vectorized<TypeParam, vector<double>, double, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdDD) {
  test_vectorized<TypeParam, vector<double>, double, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdDv) {
  test_vectorized<TypeParam, vector<double>, double, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdDV) {
  test_vectorized<TypeParam, vector<double>, double, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_Ddvd) {
  test_vectorized<TypeParam, vector<double>, double, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdvD) {
  test_vectorized<TypeParam, vector<double>, double, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_Ddvv) {
  test_vectorized<TypeParam, vector<double>, double, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdvV) {
  test_vectorized<TypeParam, vector<double>, double, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdVd) {
  test_vectorized<TypeParam, vector<double>, double, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdVD) {
  test_vectorized<TypeParam, vector<double>, double, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdVv) {
  test_vectorized<TypeParam, vector<double>, double, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DdVV) {
  test_vectorized<TypeParam, vector<double>, double, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDdd) {
  test_vectorized<TypeParam, vector<double>, vector<double>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDdD) {
  test_vectorized<TypeParam, vector<double>, vector<double>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDdv) {
  test_vectorized<TypeParam, vector<double>, vector<double>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDdV) {
  test_vectorized<TypeParam, vector<double>, vector<double>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDDd) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDDD) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDDv) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDDV) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDvd) {
  test_vectorized<TypeParam, vector<double>, vector<double>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDvD) {
  test_vectorized<TypeParam, vector<double>, vector<double>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDvv) {
  test_vectorized<TypeParam, vector<double>, vector<double>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDvV) {
  test_vectorized<TypeParam, vector<double>, vector<double>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDVd) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDVD) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDVv) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DDVV) {
  test_vectorized<TypeParam, vector<double>, vector<double>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVdd) {
  test_vectorized<TypeParam, vector<double>, vector<var>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVdD) {
  test_vectorized<TypeParam, vector<double>, vector<var>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVdv) {
  test_vectorized<TypeParam, vector<double>, vector<var>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVdV) {
  test_vectorized<TypeParam, vector<double>, vector<var>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVDd) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVDD) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVDv) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVDV) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVvd) {
  test_vectorized<TypeParam, vector<double>, vector<var>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVvD) {
  test_vectorized<TypeParam, vector<double>, vector<var>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVvv) {
  test_vectorized<TypeParam, vector<double>, vector<var>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVvV) {
  test_vectorized<TypeParam, vector<double>, vector<var>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVVd) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVVD) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVVv) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture4, vectorized_DVVV) {
  test_vectorized<TypeParam, vector<double>, vector<var>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vddd) {
  test_vectorized<TypeParam, var, double, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vddD) {
  test_vectorized<TypeParam, var, double, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vddv) {
  test_vectorized<TypeParam, var, double, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vddV) {
  test_vectorized<TypeParam, var, double, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdDd) {
  test_vectorized<TypeParam, var, double, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdDD) {
  test_vectorized<TypeParam, var, double, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdDv) {
  test_vectorized<TypeParam, var, double, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdDV) {
  test_vectorized<TypeParam, var, double, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdvd) {
  test_vectorized<TypeParam, var, double, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdvD) {
  test_vectorized<TypeParam, var, double, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdvv) {
  test_vectorized<TypeParam, var, double, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdvV) {
  test_vectorized<TypeParam, var, double, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdVd) {
  test_vectorized<TypeParam, var, double, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdVD) {
  test_vectorized<TypeParam, var, double, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdVv) {
  test_vectorized<TypeParam, var, double, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vdVV) {
  test_vectorized<TypeParam, var, double, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDdd) {
  test_vectorized<TypeParam, var, vector<double>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDdD) {
  test_vectorized<TypeParam, var, vector<double>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDdv) {
  test_vectorized<TypeParam, var, vector<double>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDdV) {
  test_vectorized<TypeParam, var, vector<double>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDDd) {
  test_vectorized<TypeParam, var, vector<double>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDDD) {
  test_vectorized<TypeParam, var, vector<double>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDDv) {
  test_vectorized<TypeParam, var, vector<double>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDDV) {
  test_vectorized<TypeParam, var, vector<double>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDvd) {
  test_vectorized<TypeParam, var, vector<double>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDvD) {
  test_vectorized<TypeParam, var, vector<double>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDvv) {
  test_vectorized<TypeParam, var, vector<double>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDvV) {
  test_vectorized<TypeParam, var, vector<double>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDVd) {
  test_vectorized<TypeParam, var, vector<double>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDVD) {
  test_vectorized<TypeParam, var, vector<double>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDVv) {
  test_vectorized<TypeParam, var, vector<double>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vDVV) {
  test_vectorized<TypeParam, var, vector<double>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVdd) {
  test_vectorized<TypeParam, var, vector<var>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVdD) {
  test_vectorized<TypeParam, var, vector<var>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVdv) {
  test_vectorized<TypeParam, var, vector<var>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVdV) {
  test_vectorized<TypeParam, var, vector<var>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVDd) {
  test_vectorized<TypeParam, var, vector<var>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVDD) {
  test_vectorized<TypeParam, var, vector<var>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVDv) {
  test_vectorized<TypeParam, var, vector<var>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVDV) {
  test_vectorized<TypeParam, var, vector<var>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVvd) {
  test_vectorized<TypeParam, var, vector<var>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVvD) {
  test_vectorized<TypeParam, var, vector<var>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVvv) {
  test_vectorized<TypeParam, var, vector<var>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVvV) {
  test_vectorized<TypeParam, var, vector<var>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVVd) {
  test_vectorized<TypeParam, var, vector<var>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVVD) {
  test_vectorized<TypeParam, var, vector<var>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVVv) {
  test_vectorized<TypeParam, var, vector<var>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture5, vectorized_vVVV) {
  test_vectorized<TypeParam, var, vector<var>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_Vddd) {
  test_vectorized<TypeParam, vector<var>, double, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VddD) {
  test_vectorized<TypeParam, vector<var>, double, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_Vddv) {
  test_vectorized<TypeParam, vector<var>, double, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VddV) {
  test_vectorized<TypeParam, vector<var>, double, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdDd) {
  test_vectorized<TypeParam, vector<var>, double, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdDD) {
  test_vectorized<TypeParam, vector<var>, double, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdDv) {
  test_vectorized<TypeParam, vector<var>, double, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdDV) {
  test_vectorized<TypeParam, vector<var>, double, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_Vdvd) {
  test_vectorized<TypeParam, vector<var>, double, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdvD) {
  test_vectorized<TypeParam, vector<var>, double, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_Vdvv) {
  test_vectorized<TypeParam, vector<var>, double, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdvV) {
  test_vectorized<TypeParam, vector<var>, double, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdVd) {
  test_vectorized<TypeParam, vector<var>, double, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdVD) {
  test_vectorized<TypeParam, vector<var>, double, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdVv) {
  test_vectorized<TypeParam, vector<var>, double, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VdVV) {
  test_vectorized<TypeParam, vector<var>, double, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDdd) {
  test_vectorized<TypeParam, vector<var>, vector<double>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDdD) {
  test_vectorized<TypeParam, vector<var>, vector<double>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDdv) {
  test_vectorized<TypeParam, vector<var>, vector<double>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDdV) {
  test_vectorized<TypeParam, vector<var>, vector<double>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDDd) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDDD) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDDv) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDDV) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDvd) {
  test_vectorized<TypeParam, vector<var>, vector<double>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDvD) {
  test_vectorized<TypeParam, vector<var>, vector<double>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDvv) {
  test_vectorized<TypeParam, vector<var>, vector<double>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDvV) {
  test_vectorized<TypeParam, vector<var>, vector<double>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDVd) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDVD) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDVv) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VDVV) {
  test_vectorized<TypeParam, vector<var>, vector<double>, vector<var>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVdd) {
  test_vectorized<TypeParam, vector<var>, vector<var>, double, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVdD) {
  test_vectorized<TypeParam, vector<var>, vector<var>, double, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVdv) {
  test_vectorized<TypeParam, vector<var>, vector<var>, double, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVdV) {
  test_vectorized<TypeParam, vector<var>, vector<var>, double, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVDd) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<double>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVDD) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<double>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVDv) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<double>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVDV) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<double>, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVvd) {
  test_vectorized<TypeParam, vector<var>, vector<var>, var, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVvD) {
  test_vectorized<TypeParam, vector<var>, vector<var>, var, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVvv) {
  test_vectorized<TypeParam, vector<var>, vector<var>, var, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVvV) {
  test_vectorized<TypeParam, vector<var>, vector<var>, var, vector<var> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVVd) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<var>, double >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVVD) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<var>, vector<double> >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVVv) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<var>, var >();
}
TYPED_TEST_P(AgradDistributionTestFixture6, vectorized_VVVV) {
  test_vectorized<TypeParam, vector<var>, vector<var>, vector<var>, vector<var> >();
}

// This has a limit of 50 tests.
REGISTER_TYPED_TEST_CASE_P(AgradDistributionTestFixture,
			   call_all_versions,
			   check_valid_dddd,
			   check_valid_dddv,
			   check_valid_ddvd,
			   check_valid_ddvv,
			   check_valid_dvdd,
			   check_valid_dvdv,
			   check_valid_dvvd,
			   check_valid_dvvv,
			   check_valid_vddd,
			   check_valid_vddv,
			   check_valid_vdvd,
			   check_valid_vdvv,
			   check_valid_vvdd,
			   check_valid_vvdv,
			   check_valid_vvvd,
			   check_valid_vvvv,
			   check_invalid_dddd,
			   check_invalid_dddv,
			   check_invalid_ddvd,
			   check_invalid_ddvv,
			   check_invalid_dvdd,
			   check_invalid_dvdv,
			   check_invalid_dvvd,
			   check_invalid_dvvv,
			   check_invalid_vddd,
			   check_invalid_vddv,
			   check_invalid_vdvd,
			   check_invalid_vdvv,
			   check_invalid_vvdd,
			   check_invalid_vvdv,
			   check_invalid_vvvd,
			   check_invalid_vvvv);
REGISTER_TYPED_TEST_CASE_P(AgradDistributionTestFixture2,
			   logprob_propto_dddd,
			   logprob_propto_dddv,
			   logprob_propto_ddvd,
			   logprob_propto_ddvv,
			   logprob_propto_dvdd,
			   logprob_propto_dvdv,
			   logprob_propto_dvvd,
			   logprob_propto_dvvv,
			   logprob_propto_vddd,
			   logprob_propto_vddv,
			   logprob_propto_vdvd,
			   logprob_propto_vdvv,
			   logprob_propto_vvdd,
			   logprob_propto_vvdv,
			   logprob_propto_vvvd,
			   logprob_propto_vvvv,
			   gradient_finite_diff_dddd,
			   gradient_finite_diff_dddv,
			   gradient_finite_diff_ddvd,
			   gradient_finite_diff_ddvv,
			   gradient_finite_diff_dvdd,
			   gradient_finite_diff_dvdv,
			   gradient_finite_diff_dvvd,
			   gradient_finite_diff_dvvv,
			   gradient_finite_diff_vddd,
			   gradient_finite_diff_vddv,
			   gradient_finite_diff_vdvd,
			   gradient_finite_diff_vdvv,
			   gradient_finite_diff_vvdd,
			   gradient_finite_diff_vvdv,
			   gradient_finite_diff_vvvd,
			   gradient_finite_diff_vvvv,
			   gradient_function_dddd,
			   gradient_function_dddv,
			   gradient_function_ddvd,
			   gradient_function_ddvv,
			   gradient_function_dvdd,
			   gradient_function_dvdv,
			   gradient_function_dvvd,
			   gradient_function_dvvv,
			   gradient_function_vddd,
			   gradient_function_vddv,
			   gradient_function_vdvd,
			   gradient_function_vdvv,
			   gradient_function_vvdd,
			   gradient_function_vvdv,
			   gradient_function_vvvd,
			   gradient_function_vvvv);
REGISTER_TYPED_TEST_CASE_P(AgradDistributionTestFixture3,
			   vectorized_dddd,
			   vectorized_dddD,
			   vectorized_dddv,
			   vectorized_dddV,
			   vectorized_ddDd,
			   vectorized_ddDD,
			   vectorized_ddDv,
			   vectorized_ddDV,
			   vectorized_ddvd,
			   vectorized_ddvD,
			   vectorized_ddvv,
			   vectorized_ddvV,
			   vectorized_ddVd,
			   vectorized_ddVD,
			   vectorized_ddVv,
			   vectorized_ddVV,
			   vectorized_dDdd,
			   vectorized_dDdD,
			   vectorized_dDdv,
			   vectorized_dDdV,
			   vectorized_dDDd,
			   vectorized_dDDD,
			   vectorized_dDDv,
			   vectorized_dDDV,
			   vectorized_dDvd,
			   vectorized_dDvD,
			   vectorized_dDvv,
			   vectorized_dDvV,
			   vectorized_dDVd,
			   vectorized_dDVD,
			   vectorized_dDVv,
			   vectorized_dDVV,
			   vectorized_dVdd,
			   vectorized_dVdD,
			   vectorized_dVdv,
			   vectorized_dVdV,
			   vectorized_dVDd,
			   vectorized_dVDD,
			   vectorized_dVDv,
			   vectorized_dVDV,
			   vectorized_dVvd,
			   vectorized_dVvD,
			   vectorized_dVvv,
			   vectorized_dVvV,
			   vectorized_dVVd,
			   vectorized_dVVD,
			   vectorized_dVVv,
			   vectorized_dVVV);
REGISTER_TYPED_TEST_CASE_P(AgradDistributionTestFixture4,
			   vectorized_Dddd,
			   vectorized_DddD,
			   vectorized_Dddv,
			   vectorized_DddV,
			   vectorized_DdDd,
			   vectorized_DdDD,
			   vectorized_DdDv,
			   vectorized_DdDV,
			   vectorized_Ddvd,
			   vectorized_DdvD,
			   vectorized_Ddvv,
			   vectorized_DdvV,
			   vectorized_DdVd,
			   vectorized_DdVD,
			   vectorized_DdVv,
			   vectorized_DdVV,
			   vectorized_DDdd,
			   vectorized_DDdD,
			   vectorized_DDdv,
			   vectorized_DDdV,
			   vectorized_DDDd,
			   vectorized_DDDD,
			   vectorized_DDDv,
			   vectorized_DDDV,
			   vectorized_DDvd,
			   vectorized_DDvD,
			   vectorized_DDvv,
			   vectorized_DDvV,
			   vectorized_DDVd,
			   vectorized_DDVD,
			   vectorized_DDVv,
			   vectorized_DDVV,
			   vectorized_DVdd,
			   vectorized_DVdD,
			   vectorized_DVdv,
			   vectorized_DVdV,
			   vectorized_DVDd,
			   vectorized_DVDD,
			   vectorized_DVDv,
			   vectorized_DVDV,
			   vectorized_DVvd,
			   vectorized_DVvD,
			   vectorized_DVvv,
			   vectorized_DVvV,
			   vectorized_DVVd,
			   vectorized_DVVD,
			   vectorized_DVVv,
			   vectorized_DVVV);
REGISTER_TYPED_TEST_CASE_P(AgradDistributionTestFixture5,
			   vectorized_vddd,
			   vectorized_vddD,
			   vectorized_vddv,
			   vectorized_vddV,
			   vectorized_vdDd,
			   vectorized_vdDD,
			   vectorized_vdDv,
			   vectorized_vdDV,
			   vectorized_vdvd,
			   vectorized_vdvD,
			   vectorized_vdvv,
			   vectorized_vdvV,
			   vectorized_vdVd,
			   vectorized_vdVD,
			   vectorized_vdVv,
			   vectorized_vdVV,
			   vectorized_vDdd,
			   vectorized_vDdD,
			   vectorized_vDdv,
			   vectorized_vDdV,
			   vectorized_vDDd,
			   vectorized_vDDD,
			   vectorized_vDDv,
			   vectorized_vDDV,
			   vectorized_vDvd,
			   vectorized_vDvD,
			   vectorized_vDvv,
			   vectorized_vDvV,
			   vectorized_vDVd,
			   vectorized_vDVD,
			   vectorized_vDVv,
			   vectorized_vDVV,
			   vectorized_vVdd,
			   vectorized_vVdD,
			   vectorized_vVdv,
			   vectorized_vVdV,
			   vectorized_vVDd,
			   vectorized_vVDD,
			   vectorized_vVDv,
			   vectorized_vVDV,
			   vectorized_vVvd,
			   vectorized_vVvD,
			   vectorized_vVvv,
			   vectorized_vVvV,
			   vectorized_vVVd,
			   vectorized_vVVD,
			   vectorized_vVVv,
			   vectorized_vVVV);
REGISTER_TYPED_TEST_CASE_P(AgradDistributionTestFixture6,
			   vectorized_Vddd,
			   vectorized_VddD,
			   vectorized_Vddv,
			   vectorized_VddV,
			   vectorized_VdDd,
			   vectorized_VdDD,
			   vectorized_VdDv,
			   vectorized_VdDV,
			   vectorized_Vdvd,
			   vectorized_VdvD,
			   vectorized_Vdvv,
			   vectorized_VdvV,
			   vectorized_VdVd,
			   vectorized_VdVD,
			   vectorized_VdVv,
			   vectorized_VdVV,
			   vectorized_VDdd,
			   vectorized_VDdD,
			   vectorized_VDdv,
			   vectorized_VDdV,
			   vectorized_VDDd,
			   vectorized_VDDD,
			   vectorized_VDDv,
			   vectorized_VDDV,
			   vectorized_VDvd,
			   vectorized_VDvD,
			   vectorized_VDvv,
			   vectorized_VDvV,
			   vectorized_VDVd,
			   vectorized_VDVD,
			   vectorized_VDVv,
			   vectorized_VDVV,
			   vectorized_VVdd,
			   vectorized_VVdD,
			   vectorized_VVdv,
			   vectorized_VVdV,
			   vectorized_VVDd,
			   vectorized_VVDD,
			   vectorized_VVDv,
			   vectorized_VVDV,
			   vectorized_VVvd,
			   vectorized_VVvD,
			   vectorized_VVvv,
			   vectorized_VVvV,
			   vectorized_VVVd,
			   vectorized_VVVD,
			   vectorized_VVVv,
			   vectorized_VVVV);

#endif