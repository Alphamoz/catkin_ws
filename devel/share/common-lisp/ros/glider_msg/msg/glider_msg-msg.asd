
(cl:in-package :asdf)

(defsystem "glider_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "cobamsg" :depends-on ("_package_cobamsg"))
    (:file "_package_cobamsg" :depends-on ("_package"))
    (:file "dvlmsg" :depends-on ("_package_dvlmsg"))
    (:file "_package_dvlmsg" :depends-on ("_package"))
  ))