#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/Report.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject

{

	Report* build_report(int start, int end)
	{
		Report* report = new Report;
		report->start = start;
		report->end = end;
		return report;
	}

	void delete_report(Report* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Report* reports[3];
			reports[0] = build_report(900, 1100);
			reports[1] = build_report(730, 930);
			reports[2] = build_report(1200, 1700);
			Assert::AreEqual(500, process(reports, 3));
			delete_report(reports, 3);

		}

		TEST_METHOD(TestMethod2)
		{
			Report* reports[3];
			reports[0] = build_report(940, 1120);
			reports[1] = build_report(730, 830);
			reports[2] = build_report(1200, 1230);
			Assert::AreEqual(140, process(reports, 3));
			delete_report(reports, 3);

		}
	};
}
