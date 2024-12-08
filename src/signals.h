#pragma once

#include <functional>

namespace signals {

template <typename T>
class signal;

template <typename... Args>
class signal<void(Args...)> {
public:
  using slot = std::function<void(Args...)>;

  class connection {
  public:
    connection() noexcept;

    void disconnect() noexcept;
  };

  signal() noexcept;

  signal(const signal&) = delete;
  signal& operator=(const signal&) = delete;

  signal(signal&&) noexcept;
  signal& operator=(signal&&) noexcept;

  ~signal();

  connection connect(slot slot) noexcept;

  void operator()(Args...) const;
};

} // namespace signals
