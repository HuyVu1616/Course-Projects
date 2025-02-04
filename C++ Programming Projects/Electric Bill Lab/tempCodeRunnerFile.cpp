 try 
    {
        if (!cin)
            throw 0;
        if (kWh < 0)
            throw 0;
    }
    catch (int errID)
    {
        cerr << "Error: " << errID << endl;
        cerr << "kWh must be a positive number" << endl;
    }