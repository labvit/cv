#ifndef DEMO_HPP

class DemoScene
{
  std::vector<std::unique_ptr<IShape>> _shapes;

  DemoScene(){}

public:
  // singleton
  static DemoScene& Instance()
  {
    static DemoScene _Instance;
    return _Instance;
  }
  void Init();
  void Draw(IContext2D* ctx);
};
#endif 