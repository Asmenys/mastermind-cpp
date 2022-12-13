class Arg_Interpretor{
    public:
        static void interpret_args(int argc, char *argv[]);
    private:
        static void call_comand(char argv);
};