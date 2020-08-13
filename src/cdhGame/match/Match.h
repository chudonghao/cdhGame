//
// Created by chudonghao on 2020/8/9.
//

#ifndef CDHGAME_06DA00A13AEB4C27AD8B723F5326EC5B_
#define CDHGAME_06DA00A13AEB4C27AD8B723F5326EC5B_

namespace cdhMc {

class Match {
public:
  explicit Match(int id);

public:
  void start();
private:
  int _id{};
};

} // namespace cdhMc

#endif // CDHGAME_06DA00A13AEB4C27AD8B723F5326EC5B_
