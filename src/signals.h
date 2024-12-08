#pragma once

#include <functional>

namespace signals {

template <typename T>
struct signal;

template <typename... Args>
struct signal<void(Args...)> {
  using slot = std::function<void(Args...)>;

  struct connection {
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
