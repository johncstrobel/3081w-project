void GraphicsArenaViewer::AddEntityPanel(nanogui::Widget * panel) {
  // .....
  std::vector<nanogui::Widget*> robotWidgets;
  // .....

  // ************************************************ //
  // ******* Create the Wheel Velocity Grid  ******** //
  robotWidgets.push_back(new nanogui::Label(
    panel, "Wheel Velocities", "sans-bold"));
  nanogui::Widget* grid = new nanogui::Widget(panel);
  // A grid with 3 columns
  grid->setLayout(
    new nanogui::GridLayout(nanogui::Orientation::Horizontal, 3, nanogui::Alignment::Middle, /*int margin = */0, /*int spacing = */0)
  );
  robotWidgets.push_back(grid);

  // Columns Headers Row
  // Notice that it is assigning these items to grid locations row by row
  new nanogui::Label(grid, "", "sans-bold");
  new nanogui::Label(grid, "Left", "sans-bold");
  new nanogui::Label(grid, "Right", "sans-bold");

  // Next Row for wheel velocities from light behavior
  new nanogui::Label(grid, "Light", "sans-bold");
  nanogui::TextBox* light_value_left_ = new nanogui::TextBox(grid, "0.0");
  light_value_left_->setFixedWidth(75);
  nanogui::TextBox* light_value_right_ = new nanogui::TextBox(grid, "0.0");
  light_value_right_->setFixedWidth(75);
  // Save these text boxes so they can be filled with values in real-time
  // Using the observer pattern
  my_velocity_container_light_.StoreBoxes(
    light_value_left_, light_value_right_);
  // Continue with this to create a complete grid of wheel velocities
  // ...

  // ****************************************************************** //
  // **** EXAMPLE code snippets for subscribing and unsubscribing ***** //
  // ...
  entitySelect->setCallback(
    [this, isMobile, robotWidgets, lightBehaviorSelect,
    foodBehaviorSelect, robotBehaviorSelect](int index) {
      if (/* Already observing a robot */) {
        // Unsubscribe from that one
      }
      // ...
      if (entity->get_type() == kBraitenberg) {
        // ...
        // Subscribe to observe this one
      }
}

// EXAMPLE of setting the value to be displayed in the velocity grid
void SomeFunction(const WheelVelocity& wv) {
  my_velocity_container_light_.left_->
    setValue(formatValue(wv.left_))
}
