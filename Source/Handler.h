class Handler {
	public:
		void Handler();
		virtual void setCallback(Callback);
	private:
		static typedef void(*Callback)();
		Callback m_Callback;
}