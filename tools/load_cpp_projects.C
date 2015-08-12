{
    std::string const cpp_projects_path = gSystem->Getenv("CPP_PROJECTS");
    if (!cpp_projects_path.empty())
    {
        // set debug if debug ROOT build
        TString rootsys = gSystem->Getenv("ROOTSYS");
        if (rootsys.Contains("debug"))
        {
            gSystem->SetAclicMode(TSystem::kDebug);
        }
        const bool is_debug = (gSystem->GetAclicMode()==TSystem::kDebug);

        std::string const cpp_projects_bin = (is_debug ? "/bin/debug" : "/bin/release");
        if (is_debug)
        {
            cout << "CPP_PROJECTS path set to: " << cpp_projects_bin << endl;
        }
        if (is_debug)
        {
            cout << "Dynamic path set to: " << cpp_projects_bin << endl;
            cout << gSystem->GetDynamicPath() << endl;
        }

        // load libraries 
        gROOT->ProcessLine(Form(".x %s/libs/language_tools/macros/load_language_tools.C", cpp_projects_path.c_str()));
    }
}

