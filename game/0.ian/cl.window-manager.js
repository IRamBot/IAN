
var ian_wm = (function() {

  // Create a div to contain and display notifications
  var notifContainer = jQ("<div>", {id:"ian-notif-container"}).appendTo("#ian-main");

  // ian_wm public functions
  return {

    // Send a notification to the user
    notify: function(message, cssclass, timeout) {
      // Create notification
      var notif = jQ("<p>")
        .addClass("ian-notif")
        .text(message)
        .appendTo(notifContainer);

      if (typeof(cssclass) !== "undefined") notif.addClass("ian-notif-"+cssclass);
      if (typeof(timeout) == "undefined") timeout = 15;

      // TODO Icons ?
      /*if (cssclass === "error") {
        jQ("<i>").addClass("fa").addClass("fa-fw")
          .addClass("fa-exclamation-triangle").prependTo(notif);
      }*/

      // Dismiss on click
      notif.click(function() {
        notif.fadeOut(200, function() {
          notif.remove();
        });
      });

      // Dismiss on timeout
      if (timeout > 0) {
        setTimeout(function() {
          notif.fadeOut(600, function() {
            notif.remove();
          });
        }, timeout * 1000);
      }
    }

  };
}());
