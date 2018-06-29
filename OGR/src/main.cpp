#include<iostream>

using namespace std;


#include<iostream>
#include "OGRMBR.h"
#include "OGRGeometry.h"
#include "OGRPoint.h"
#include "OGRCurve.h"
#include "OGRSimpleCurve.h"
#include "OGRLineString.h"

#include "OGRSurface.h"
#include "OGRCurvePolygon.h"
#include "OGRPolygon.h"


#include<vector>

using namespace std;

namespace testing {
    enum OGRName {
        OGRPoint = 0,
        OGRPolygon = 1,
        OGRMultiPoint = 2,
        OGRMultiPolygon = 3
    };
}

class TestGeometry {
private:


    string OGRName2String(testing::OGRName ogrName) {
        string s = "";
        switch (testing::OGRName(ogrName)) {
            case testing::OGRPoint:
                s = "OGRPoint";
                break;
            case testing::OGRPolygon:
                s = "OGRPolygon";
                break;
            case testing::OGRMultiPoint:
                s = "OGRMultiPoint";
                break;
            case testing::OGRMultiPolygon:
                s = "OGRMultiPolygon";
                break;
            default:
                break;
        }
        return s;
    }

public:

    void Test_Geometry_ImportFromWkt(string path, OGRGeometry *geometry) {
        if (path.empty() || !geometry)
            return;

        try {
            geometry->ImportFromWkt(path);
        }
        catch (exception &e) {
            cout << "Exception: " << e.what() << endl;
        }
    }

    void Test_Geometry_ExportToWkt(string path, OGRGeometry *geometry) {

        if (path.empty() || !geometry)
            return;

        try {
            geometry->ExportToWkt(path);
        }
        catch (exception &e) {
            cout << "Exception: " << e.what() << endl;
        }

    }

    void Test_Geometry(string filepath, string filename_import_template, string filename_export_template) {
        OGRGeometry *geometry;
        for (int i = 0; i < 4; i++) {
            switch (testing::OGRName(i)) {
                case testing::OGRPoint:
                    geometry = new OGRPoint();
                    break;
                case testing::OGRPolygon:
                    geometry = new OGRPolygon();
                    break;
                case testing::OGRMultiPoint:
                    geometry = new OGRMultiPoint();
                    break;
                case testing::OGRMultiPolygon:
                    geometry = new OGRMultiPolygon();
                    break;
                default:
                    break;
            }

            Test_Geometry_ImportFromWkt(filepath + OGRName2String(testing::OGRName(i)) + filename_import_template,
                                        geometry);
            Test_Geometry_ExportToWkt(filepath + OGRName2String(testing::OGRName(i)) + filename_export_template,
                                      geometry);
        }
    }
};


int main() {

    //Filepath
    string filepath = "../test/";

    //filename template
    string filename_import_template = "_import.txt";
    string filename_export_template = "_export.txt";

    //Test
    TestGeometry *test_geometry = new TestGeometry();
    test_geometry->Test_Geometry(filepath, filename_import_template, filename_export_template);

	
    system("pause");
    return 0;
}


