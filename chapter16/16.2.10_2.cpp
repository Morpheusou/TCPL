struct Link {
	Link* pre;
	Link* suc;
	int date;

	Link* insert(int x) // insert x before this
	{
		return pre = new Link{pre, this, x};
	}

	void remove()
	{
		if (pre) pre->suc = suc;
		if (suc) suc->pre = pre;
		delete this;
	}

	// ...
};
