{
    // load the AnalysisTools for interactive use 
    std::cout << "Loading LanguageTools" << std::endl;
    std::string const language_tools_include_path = Form("%s/libs/language_tools/include", gSystem->Getenv("CPP_PROJECTS"));
    gInterpreter->AddIncludePath(language_tools_include_path.c_str());
    gROOT->ProcessLine(Form("#include \"lt/language_tools.hpp\""));
    gSystem->Load("$CPP_PROJECTS/bin/release/liblanguage_tools.so")
}
